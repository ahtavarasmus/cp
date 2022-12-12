#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif

void debug_heights(auto &heights)
{
    for (int x = 0; x < heights.size(); x++){
        for (int y = 0; y < heights[x].size(); ++y){
            cout << heights[x][y];
        }
        cout << endl;
    }
}

void solve(){
    string line;
    // y-x coords
    vector<vector<int>> heights;
    int grid_width;
    int grid_height;
    // x coords
    vector<int> tmp;
    // first=y-second=x
    pair<int,int> start;
    pair<int,int> end;
    int height;

    int y = 0;
    while (true){
        tmp.clear();
        getline(cin,line);
        if (!line.size()) break;

        for (int x = 0; x < line.size(); ++x){
            if (line[x] == 'S'){
                start.first = y,start.second = x;
                height = 0;
            } else if (line[x] == 'E'){
                end.first = y,end.second = x;
                height = 'z'-'a';
            } else {
                height = line[x]-'a';
            }
            tmp.push_back(height);
        }
        grid_width = tmp.size();
        heights.push_back(tmp);
        ++y;
    }
    grid_height = y;
    // value is distance to that point
    map<pair<int,int>,int> visited;
    // path back to starting node
    map<pair<int,int>,pair<int,int>> parents;

    queue<pair<int,int>> q;
    pair<int,int> cur;
    cur = start;
    q.push(cur);
    visited[cur] = 0;
    int new_height;
    while (!q.empty()){
        cur = q.front();
        q.pop();
        height = heights[cur.first][cur.second];

        if (cur == end){
            // path found
            int steps = 0;
            while (heights[cur.first][cur.second] != 0){
                cur = parents[cur];
                steps++;
            }
            cout << "fewest steps: " << steps;
            return;
        }
        pair<int,int> new_pair;

        // check up
        if (cur.first-1 > -1){
            new_pair = make_pair(cur.first-1,cur.second);
            new_height = heights[new_pair.first][new_pair.second];
            if ((new_height-height) < 2 and visited.find(new_pair) == visited.end()){
                // distance here is one more than to parent point
                visited[new_pair] = visited[cur]+1;
                parents[new_pair] = cur;
                q.push(new_pair);
            }
        }
        // check bottom 
        if (cur.first+1 < grid_height){
            new_pair = make_pair(cur.first+1,cur.second);
            new_height = heights[new_pair.first][new_pair.second];

            if ((new_height-height) < 2 and visited.find(new_pair) == visited.end()){
                // distance here is one more than to parent point
                visited[new_pair] = visited[cur]+1;
                parents[new_pair] = cur;
                q.push(new_pair);
            }
        }
        // check left 
        if (cur.second-1 > -1){
            new_pair = make_pair(cur.first,cur.second-1);
            new_height = heights[new_pair.first][new_pair.second];
            if ((new_height-height < 2) and visited.find(new_pair) == visited.end()){
                // distance here is one more than to parent point
                visited[new_pair] = visited[cur]+1;
                parents[new_pair] = cur;
                q.push(new_pair);
            }
        }
        // check right 
        if (cur.second+1 < grid_width){
            new_pair = make_pair(cur.first,cur.second+1);
            new_height = heights[new_pair.first][new_pair.second];
            
            if ((new_height-height) < 2 and visited.find(new_pair) == visited.end()){
                // distance here is one more than to parent point
                visited[new_pair] = visited[cur]+1;
                parents[new_pair] = cur;
                q.push(new_pair);
            }
        }

        debug("aha")

    }
    cout << "didn't find path";
    

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
