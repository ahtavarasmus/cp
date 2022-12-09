#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif

struct tree {
    int height;
    int top;
    int top_dist;
    int right;
    int right_dist;
    int bottom;
    int bottom_dist;
    int left;
    int left_dist;
};
typedef struct tree tree;

void solve(){
    string line;

    // fill grid
    vector<vector<tree> > grid;
    vector<tree> l;
    for (int x = 0; x < 99; ++x){
        getline(cin,line);
        l.clear();
        for (int y = 0; y < 99; ++y){
            tree cur;
            cur.height = stoi(line.substr(y,1));
            l.push_back(cur);
        }
        grid.push_back(l);
    }
    int max_scenic = 0;
    for (int x = 1; x < 98; ++x){
        for (int y= 1; y < 98; ++y){
            // right
            int d = y+1;
            int dist = 1;
            while (true){
                if (d == 98 or grid[x][d].height >= grid[x][y].height)
                    break;
                d++;
                dist++;
            }
            grid[x][y].right = dist;

            // left
            d = y-1;
            dist = 1;
            while (true){
                if (d == 0 or grid[x][d].height >= grid[x][y].height)
                    break;
                d--;
                dist++;
            }
            grid[x][y].left = dist;
            // top
            d = x-1;
            dist = 1;
            while (true){
                if (d == 0 or grid[d][y].height >= grid[x][y].height)
                    break;
                d--;
                dist++;
            }
            grid[x][y].top = dist;
                        // bottom
            d = x+1;
            dist = 1;
            while (true){
                if (d == 98 or grid[d][y].height >= grid[x][y].height)
                    break;
                d++;
                dist++;
            }
            grid[x][y].bottom = dist;

            int scenic = grid[x][y].top*grid[x][y].right*grid[x][y].left*
                grid[x][y].bottom;
            debug(scenic)
            max_scenic = max(scenic,max_scenic);
            debug(max_scenic)
        }
    }
    cout << max_scenic;
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
