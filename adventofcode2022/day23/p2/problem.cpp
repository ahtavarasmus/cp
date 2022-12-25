#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif

struct P {
    int y,x;

    P() : y(0),x(0) {};
    P(const int& y,const int& x) : y(y),x(x) {};
    P(const P& other){x = other.x,y = other.y;};

    bool operator<(const P &p) const {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }
    bool operator==(const P &p) const {
        return (x == p.x) and (y == p.y);
    };
    bool operator>(const P &p) const {
        if (x != p.x) return x > p.x;
        return y > p.y;
    };
    P& operator=(const P& other){
        y = other.y;
        x = other.x;
        return *this;
    };
    size_t operator()(const P& pointToHash) const noexcept {
        size_t hash = pointToHash.x + 10*pointToHash.y;
        return hash;
    };
};

namespace std {
    template<> struct hash<P>
    {
        std::size_t operator()(const P& p) const noexcept {
            return p(p);
        }
    };
}


bool no_adjacents(P point,unordered_set<P> &elves)
{
    P cur;
    for (int y = point.y-1; y <= point.y+1; ++y){
        for (int x = point.x-1; x <= point.x+1; ++x){
            if (x==point.x and y==point.y) continue;
            cur.x = x;
            cur.y = y;
            if (elves.contains(cur)) return false;
        }
    }
    return true;
}

bool dir_okay(P point,string dir,unordered_set<P> &elves)
{
    P cur;
    if (dir == "n"){
        for (int x = point.x-1; x <= point.x+1; ++x){
            cur.x = x,cur.y = point.y-1;
            if (elves.contains(cur)) return false;
        }
    } else if (dir == "s"){
        for (int x = point.x-1; x <= point.x+1; ++x){
            cur.x = x,cur.y = point.y+1;
            if (elves.contains(cur)) return false;
        }
    } else if (dir == "w"){
        for (int y = point.y-1; y <= point.y+1; ++y){
            cur.y = y,cur.x = point.x-1;
            if (elves.contains(cur)) return false;
        }
    } else {
        for (int y = point.y-1; y <= point.y+1; ++y){
            cur.y = y; cur.x = point.x+1;
            if (elves.contains(cur)) return false;
        }
    }
    return true;
}

void print_elves(const unordered_set<P> &elves,int top,int bottom,int left,int right)
{
    P cur;
    for (int y = top; y <= bottom; ++y){
        for (int x = left; x <= right; ++x){
            cur.x = x,cur.y = y;
            if (elves.contains(cur)){
                cout << "#";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
}

void solve(){
    // current elves in the map
    unordered_set<P> elves;
    string line;
    int ln;
    int y = 0;
    int left=INT_MAX,right=INT_MIN,top=INT_MAX,bottom=INT_MIN;
    while (getline(cin,line)){
        ln = line.size();
        if (!ln) break;
        for (int x = 0; x < ln; ++x){
            if (line[x] == '#'){
                P p(y,x);
                elves.insert(p);
            }
        }
        right = ln;
        bottom = y;
        ++y;
    }

    list<string> dirs;
    // where elves want to go(key) and all the elves that want to go there(value)
    unordered_map<P,set<P>> proposed_elves;
    dirs.push_back("n"),dirs.push_back("s");
    dirs.push_back("w"),dirs.push_back("e");
    // keeps track of the number of elves that don't need to move
    int stay_count = 0;
    // round number
    int r = 0;
    while (true){
        cout << endl;
        proposed_elves.clear();
        stay_count = 0;
        for (auto &elf : elves){
            P cur(elf);
            // if this elf doesn't need to move, insert is as it is.
            if (no_adjacents(cur,elves)){
                proposed_elves[cur].insert(elf);
                stay_count++;
                continue;
            }
            for (auto &dir : dirs){
                // if direction was okay
                if (dir_okay(cur,dir,elves)){
                    // move elf if possible
                    if (dir == "n") cur.y--;
                    else if (dir == "s") cur.y++;
                    else if (dir == "w") cur.x--;
                    else cur.x++;
                    break;
                }
            }
            // insert (moved elf) or (elf that couldn't move)
            proposed_elves[cur].insert(elf);
        }
        // check if all elves didn't have to move (answer)
        if (stay_count == proposed_elves.size()){
            cout << "ROUND " << r+1 << endl;
            break;
        }
        elves.clear();
        // cycle directions
        dirs.push_back(dirs.front());
        dirs.pop_front();

        for (auto &elf : proposed_elves){
            // if only one elf was going to that spot
            if (elf.second.size() == 1){
                elves.insert(elf.first);
            } else {
                // otherwise keep all those elves were they were
                for (auto &par : elf.second){
                    elves.insert(par);
                }
            }
        }

        // check the map size
        int left=INT_MAX,right=INT_MIN,top=INT_MAX,bottom=INT_MIN;
        for (auto &elf : elves){
            top = min(top,elf.y);
            bottom = max(bottom,elf.y);
            right = max(right,elf.x);
            left = min(left,elf.x);
        }

        cout << "round: " << r+1 << endl;
        print_elves(elves,top,bottom,left,right);
        r++;
    }


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    cout << "\n";
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
