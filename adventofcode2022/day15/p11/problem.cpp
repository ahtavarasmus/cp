#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif

struct P {
    int x,y;
    bool operator<(const P &p) const {
        if (x != p.x) return x < p.x;
        else return y < p.y;
    }
};
typedef struct P P;

int calc_man(P from, P to){return abs(from.x-to.x)+abs(from.y-to.y);}

void solve(){
    string line,tmp,sx,sy,bx,by;
    int sensor_x,sensor_y,beacon_x,beacon_y;
    // sensor is 1, beacon is 2
    map<P,P> things;
    // all sensor visible spots
    int map_width = 0;
    int map_height = 0;
    P sens,beac;
    while (getline(cin,line)){
        istringstream l(line);
        // parsing input line
        l>>tmp>>tmp>>sx>>sy>>tmp>>tmp>>tmp>>tmp>>bx>>by; 
        // coords from string to long int
        sensor_x = stoi(sx.substr(2,sx.size()-3));
        sensor_y = stoi(sy.substr(2,sy.size()-3));
        beacon_x = stoi(bx.substr(2,bx.size()-3));
        beacon_y = stoi(by.substr(2,by.size()-2));
        // updating the map 
        sens.x = sensor_x;
        sens.y = sensor_y;
        beac.x = beacon_x;
        beac.y = beacon_y;
        things[sens] = beac;
    }

    // excuding last
    map<int,vector<pair<int,int>>> ranges;
    for (auto &p : things){
        int dist = calc_man(p.first,p.second);
        int from = p.first.x,to = p.first.x+1;
        debug("new")
        debug(dist)
        for (int y = p.first.y-dist; y < p.first.y+dist; ++y){
            debug(from)
            debug(to)
            //if (!ranges.contains(y))
            ranges[y].push_back(make_pair(from,to));
        /*
            else {
                ranges[y].push_back(make_pair(from,to));
                sort(ranges[y].begin(),ranges[y].end());
                for (int x = 1; x < ranges[y].size(); ++x){
                    if (ranges[y][x-1].second >= ranges[y][x].first){
                        ranges[y][x-1].second = max(ranges[y][x-1].second,
                                ranges[y][x].second);
                        ranges[y].erase(ranges[y].begin()+x);
                        break;
                    }
                }
            }
        */
            if (y<p.first.y) from--,to++;
            else from++,to--;
        }
    }
    bool inrange = false;
    debug(ranges.size())
    /*
    for (int y = 0; y < ranges.size(); ++y){
        for (auto &range : ranges[y]){
            cout << "|start->" << range.first << ",end->" << range.second;
        }
        cout << endl;
    }
        */

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
