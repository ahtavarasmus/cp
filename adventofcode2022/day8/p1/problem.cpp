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
    int right;
    int bottom;
    int left;
};
typedef struct tree tree;

void solve(){
    string line;

    vector<vector<tree> > grid;

    // check left and top
    vector<tree> l;
    for (int x = 0; x < 99; ++x){
        getline(cin,line);
        l.clear();
        for (int y = 0; y < 99; ++y){
            tree cur;
            if (x == 0 and y == 0){
                cur.top = -1;
                cur.left = -1;
            } else if (x == 0){
                cur.top = -1;
                cur.left = max(l[y-1].left,l[y-1].height);
            } else if (y == 0){
                cur.top = max(grid[x-1][y].top,grid[x-1][y].height);
                cur.left = -1;
            } else {
                cur.top = max(grid[x-1][y].top,grid[x-1][y].height);
                cur.left = max(l[y-1].left,l[y-1].height);
            }
            cur.height = stoi(line.substr(y,1));
            cur.bottom = 0;
            cur.right = 0;
            l.push_back(cur);
        }
        grid.push_back(l);
    }
    // check right and bottom
    for (int x = 98; x > -1; --x){
        for (int y = 98; y > -1; --y){
            if (x == 98 and y == 98){
                grid[x][y].bottom = -1;
                grid[x][y].right = -1;
            } else if (x == 98){
                grid[x][y].bottom = -1;
                grid[x][y].right = max(grid[x][y+1].right,grid[x][y+1].height);
            } else if (y == 98){
                grid[x][y].right = -1;
                grid[x][y].bottom = max(grid[x+1][y].bottom,grid[x+1][y].height);
            } else {
                grid[x][y].right = max(grid[x][y+1].right,grid[x][y+1].height);
                grid[x][y].bottom = max(grid[x+1][y].bottom,grid[x+1][y].height);
            }
        }
    }


    // check visibility from (needed) all angles
    long int visible = 0;
    for (int x = 0; x < 99; ++x){
        for (int y = 0; y < 99; ++y){
            tree cur = grid[x][y];
            if (cur.top < cur.height or cur.right < cur.height or 
                    cur.bottom < cur.height or cur.left < cur.height){
                visible++;
            }
        }
    }
    cout << visible;
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
