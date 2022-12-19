#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif

void solve(){
    string line,tmp,sx,sy,bx,by;
    long int sensor_x,sensor_y,beacon_x,beacon_y;
    // sensor is 1, beacon is 2
    map<pair<long int,long int>,long int> m;
    vector<pair<long int,long int> > sensors;
    // all sensor visible spots
    set<pair<long int,long int> > visible;
    long int map_width = 0;
    long int map_height = 0;
    pair<long int,long int> cur;
    while (getline(cin,line)){
        istringstream l(line);
        // parsing input line
        l>>tmp>>tmp>>sx>>sy>>tmp>>tmp>>tmp>>tmp>>bx>>by; 
        // coords from string to long int
        sensor_x = stoi(sx.substr(2,sx.size()-3));
        sensor_y = stoi(sy.substr(2,sy.size()-3));
        beacon_x = stoi(bx.substr(2,bx.size()-3));
        beacon_y = stoi(by.substr(2,by.size()-2));
        // updating the map size
        cur.first = sensor_y;
        cur.second = sensor_x;
        // putting current sensor in map
        m[cur] = 1;
        visible.insert(cur);
        // putting current sensor in vector
        sensors.push_back(cur);
        cur.first = beacon_y,cur.second = beacon_x;
        // putting current beacon in map
        m[cur] = 2;
    }
    long int map_left = INT_MAX;
    long int map_right = INT_MIN;
    long int map_top = INT_MAX;
    long int map_bottom = INT_MIN;

    debug(sensors.size())
    for (pair<long int,long int> & sensor : sensors){
        cout << sensor.first << endl;
        queue<pair<long int,long int> > q;
        // coords and current dist
        map<pair<long int,long int>,long int> visited;
        pair<long int,long int> cur,npair;
        q.push(sensor);
        visited[sensor] = 0;
        bool beacon_found = false;
        long int beacon_dist = 0;
        debug(sensor.first)
        while (!q.empty()){
            cur = q.front();
            q.pop();


            // top
            npair = {cur.first-1,cur.second};
            if (m[npair] == 2 and !beacon_found){
                beacon_found = true;
                debug("beacon at top")
                beacon_dist = visited[cur]+1;
            }
            map_top = min(map_top,cur.first-1);
            if (!visited.contains(npair)){
                visited[npair] = visited[cur]+1;
                if (!beacon_found or (beacon_found and visited[npair] == beacon_dist)){
                    visible.insert(npair);
                    q.push(npair);
                }
            }
            // bottom
            npair = {cur.first+1,cur.second};
            if (m[npair] == 2 and !beacon_found){
                beacon_found = true;
                debug("beacon at bottom")
                beacon_dist = visited[npair]+1;
            }
            map_bottom = max(map_bottom,cur.first+1);
            if (!visited.contains(npair)){
                visited[npair] = visited[cur]+1;
                if (!beacon_found or (beacon_found and visited[npair] == beacon_dist)){
                    q.push(npair);
                    visible.insert(npair);
                }
            }
            // left
            npair = {cur.first,cur.second-1};
            if (m[npair] == 2 and !beacon_found){
                beacon_found = true;
                debug("beacon at left")
                beacon_dist = visited[cur]+1;
            }
            map_left = min(map_left,cur.second-1);
            if (!visited.contains(npair)){
                visited[npair] = visited[cur]+1;
                if (!beacon_found or (beacon_found and visited[npair] == beacon_dist)){
                    q.push(npair);
                    visible.insert(npair);
                }
            }
            // right 
            npair = {cur.first,cur.second+1};
            if (m[npair] == 2 and !beacon_found){
                beacon_found = true;
                debug("beacon at right")
                beacon_dist = visited[cur]+1;
            }
            map_right = max(map_right ,cur.second+1);
            if (!visited.contains(npair)){
                visited[npair] = visited[cur]+1;
                if (!beacon_found or (beacon_found and visited[npair] == beacon_dist)){
                    q.push(npair);
                    visible.insert(npair);
                } 
            }
        }
    }
    debug(visible.size())
    long int count = 0;
    for (long int y = map_top; y < map_bottom; ++y){
        //cout << y;
        for (long int x = map_left; x < map_right; ++x){
            pair<long int,long int> cur = {y,x};
            if (m[cur] == 2){
                //cout << "B";
            } else if (m[cur] == 1){
                //cout << "S";
            } else {
                if (visible.contains(cur)){
                    if (y == 10) ++count;
                    //cout << "#";
                } else {
                    //cout << ".";
                }
            }
        }
        //cout << endl;
    }
    

    cout << count;




    
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
