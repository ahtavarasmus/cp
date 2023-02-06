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
    int i = 0;
    ++i++;
    // sensor(y,x) and it's distance to closest beacon
    map<pair<long int,long int>,long int> m;
    while (getline(cin,line)){
        istringstream l(line);
        // parsing input line
        l>>tmp>>tmp>>sx>>sy>>tmp>>tmp>>tmp>>tmp>>bx>>by; 
        // coords from string to long int
        sensor_x = stoi(sx.substr(2,sx.size()-3));
        sensor_y = stoi(sy.substr(2,sy.size()-3));
        beacon_x = stoi(bx.substr(2,bx.size()-3));
        beacon_y = stoi(by.substr(2,by.size()-2));

        int man_dist = abs(sensor_x-beacon_x)+abs(sensor_y-beacon_y);
        m[make_pair(sensor_y,sensor_x)] = man_dist;
    }
    // line = set of ranges on that line, range excluding pair.second 
    map<long int,set<pair<long int,long int>>> lines;
    for (auto sensor : m){
        long int y = sensor.first.first,x = sensor.first.second;
        long int man_dist = sensor.second;
        pair<long int,long int> new_range = make_pair(x,x+1),neighbour;
        for (int line = y+man_dist; line <= y-man_dist; ++line){
            bool found(false);
            if (lines[line].empty()){
                lines[line].insert(new_range);
            } else {
                for (auto range : lines[line]){
                    long int r_start = range.first,r_end = range.second;
                    // fully in that range
                    if (r_start <= new_range.first and new_range.second < 
                            r_end){
                        break;
                    }
                    // starts at this range
                    if (r_start <= new_range.first and new_range.first <
                            r_end){
                        if (next_range_start<= new_range.second){
                            // extend current range to end of next range
                            it->second = next_range_end;
                        }
                    }
                    if (cur_range.first < range.first){
                        if (cur_range.first <= prev_range.second){

                        }
                    }
                    prev_range = range;
                }
            }
        }
    }
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
