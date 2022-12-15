#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif
pair<int,int>
read_coord(auto &prev,string tmp, auto &cave,auto &lowest_rock)
{
    int j = 0;
    while (tmp[j++] != ',');
    --j;
    int x = stoi(tmp.substr(0,j));
    int y = stoi(tmp.substr(j+1,tmp.size()-j));

    lowest_rock = max(lowest_rock,y);

    pair<int,int> cur;
    cur.first = y,cur.second = x;
    // y same
    if (prev.first == cur.first){
        if (prev.second > cur.second){
            while (prev.second != cur.second){
                prev.second--;
                cave[prev] = 1;
            }
            cave[prev] = 1;
        } else if (prev.second < cur.second){
            while (prev.second != cur.second){
                prev.second++;
                cave[prev] = 1;
            }
            cave[prev] = 1;
        }
    // x same
    } else if (prev.second == cur.second){
        if (prev.first > cur.first){
            while (prev.first != cur.first){
                prev.first--;
                cave[prev] = 1;
            }
            cave[prev] = 1;
        } else if (prev.first < cur.first){
            while (prev.first != cur.first){
                prev.first++;
                cave[prev] = 1;
            }
            cave[prev] = 1;
        }
    }
    cave[cur] = 1;
    return cur;
}

void print_cave(auto &cave)
{

    for (int y = 0; y < 200; ++y){
        for (int x = 0; x < 1000; ++x){
            pair<int,int> cur;
            cur.first = y;
            cur.second = x;
            if (cave.contains(cur)){
                if (cave[cur] == 3)
                    cout << "+";
                else if (cave[cur] == 2)
                    cout << "o";
                else
                    cout << "#";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
}

bool not_in_abyss(auto &cave,auto &lowest_rock)
{
    pair<int,int> sand = {0,500};
    while (!cave.contains(sand)){
        pair<int,int> next = sand;
        if (!cave.contains({sand.first+1,sand.second})){
            sand.first++;
            continue;
        }
        if (!cave.contains({sand.first+1,sand.second-1})){
            sand.first++,sand.second--;
            continue;
        }
        if (!cave.contains({sand.first+1,sand.second+1})){
            sand.first++,sand.second++;
            continue;
        }
        cave[sand] = 2;
        return true;
    }
    return false;
}

void solve(){
    string line;
    map<pair<int,int>,int> cave;
    pair<int,int> sand;
    sand.first = 0,sand.second = 500;

    int lowest_rock = 0;

    while (getline(cin,line)){
        if (!line.size()) break;

        string tmp;
        istringstream rocks(line);
        rocks >> tmp;
        int j = 0;
        while (tmp[j++] != ',');
        --j;
        int x = stoi(tmp.substr(0,j));
        int y = stoi(tmp.substr(j+1,tmp.size()-j));
        pair<int,int> prev;
        prev.first = y,prev.second = x;
        cave[prev] = 1;
        lowest_rock = max(lowest_rock,prev.first);

        while (rocks >> tmp){
            rocks >> tmp;
            prev = read_coord(prev,tmp,cave,lowest_rock);
        }
    }
    for (int l = 0; l < 1000; ++l){
        pair<int,int> cur = {lowest_rock+2,l};
        cave[cur] = 1;
    }
    lowest_rock++;

    long int units = 0;
    while (not_in_abyss(cave,lowest_rock)){
        units++;
    }
    cout << units;
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
