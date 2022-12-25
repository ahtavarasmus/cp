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
    debug(elves.size())
    debug(top)
    debug(bottom)
    debug(left)
    debug(right)
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
    int height = abs(top-bottom)+1;
    int width = abs(left-right)+1;
    cout << "height: " << height << endl;
    cout << "width: " << width << endl;
    int grid = height*width;
    cout << "empty tiles: " << grid-elves.size() << endl;
}

void solve(){
    // to point and its/their parents
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
    unordered_map<P,set<P>> proposed_elves;
    unordered_set<P> leave_empty;
    unordered_map<P,int> elf_count;
    dirs.push_back("n"),dirs.push_back("s");
    dirs.push_back("w"),dirs.push_back("e");
    debug(elves.size())
    bool cont = false;
    for (int r = 0; r < 10; ++r){
        cout << endl;
        leave_empty.clear();
        proposed_elves.clear();
        for (auto &elf : elves){
            P cur(elf);
            debug("start")
            debug(cur.x)
            debug(cur.y)
            if (no_adjacents(cur,elves)){
                elf_count[cur] = 1;
                proposed_elves[cur].insert(elf);

                debug("from noadjacents")
                debug(cur.x)
                debug(cur.y)
                debug(proposed_elves.size())
                continue;
            }
            cont = false;
            for (auto &dir : dirs){
                if (dir_okay(cur,dir,elves)){

                    // move elf if possible
                    if (dir == "n") cur.y--;
                    else if (dir == "s") cur.y++;
                    else if (dir == "w") cur.x--;
                    else cur.x++;


                    proposed_elves[cur].insert(elf);
                    debug("from dir")
                    debug(cur.x)
                    debug(cur.y)
                    debug(proposed_elves.size())
                    cont = true;
                    break;
                }
            }
            if (cont) continue;
            proposed_elves[cur].insert(elf);
            debug("from end")
            debug(cur.x)
            debug(cur.y)
            debug(proposed_elves.size())

        }
        elves.clear();
        dirs.push_back(dirs.front());
        dirs.pop_front();
        debug("HAHAHAHAHHW")
        debug(proposed_elves.size())

        for (auto &elf : proposed_elves){
            debug(elf.first.x)
            debug(elf.first.y)
            if (elf.second.size() == 1){
                elves.insert(elf.first);
            } else {
                for (auto &par : elf.second){
                    elves.insert(par);
                }
            }
        }

        int left=INT_MAX,right=INT_MIN,top=INT_MAX,bottom=INT_MIN;
        for (auto &elf : elves){
            top = min(top,elf.y);
            bottom = max(bottom,elf.y);
            right = max(right,elf.x);
            left = min(left,elf.x);
        }

        cout << "round: " << r+1 << endl;
        debug(r)
        print_elves(elves,top,bottom,left,right);
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
