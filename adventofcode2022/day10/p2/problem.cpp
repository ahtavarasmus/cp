#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif


void update_head(int &row,int &column,auto &screen,auto &screen_row)
{
    column++;
    if (column == 40){
        switch (row){
            case 0:
                row = 1;
                break;
            case 1:
                row = 2;
                break;
            case 2:
                row = 3;
                break;
            case 3:
                row = 4;
                break;
            case 4:
                row = 5;
                break;
            case 5:
                row = 6;
                break;
        };
        column = 0;
        screen.push_back(screen_row);
        screen_row.clear();
    }

}

void draw_pixel(int reg,int column,vector<string> &screen_row)
{
    if (abs(reg-column) < 2){
        screen_row.push_back("🎁");
    } else {
        screen_row.push_back("🎄");
    }
}

void solve(){
    string signal;
    int v,cycle = 0;

    vector<vector<string>> screen;
    vector<string> screen_row;

    int sum = 0;
    int reg = 1;
    int row = 0,column = 0;
    while (cin >> signal){
        if (signal == "addx"){
            cin >> v;
            cycle++;
            draw_pixel(reg,column,screen_row);
            update_head(row,column,screen,screen_row);
            cycle++;
            draw_pixel(reg,column,screen_row);
            update_head(row,column,screen,screen_row);
            reg += v;
        } else {
            cycle++;
            draw_pixel(reg,column,screen_row);
            update_head(row,column,screen,screen_row);
        }
    }
    for (int y = 0; y < 6; ++y){
        for (int x = 0; x < 40; ++x){
            cout << screen[y][x];
        }
        cout << endl;
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
