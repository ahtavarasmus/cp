#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif


void move_head(pair<int,int> &head,char dir)
{
    if (dir == 'U'){
        head.second++;
    } else if (dir == 'R'){
        head.first++;
    } else if (dir == 'D'){
        head.second--;
    } else {
        head.first--;
    }
}

bool tail_behind(const pair<int,int> &head,const pair<int,int> &tail)
{
    if (abs(head.first - tail.first) < 2 and abs(head.second-tail.second) < 2)
        return false;
    return true;
}

void move_tail(pair<int,int> &head,const pair<int,int> &tail)
{
    
}


void solve(){
    // first = x,set has y's
    map<int,set<int> > visited;
    char dir;
    int count;
    // x,y
    pair<int,int> head;
    head.first = 0,head.second = 0;
    // x,y
    pair<int,int> tail;
    tail.first = 0,tail.second = 0;
    while (cin >> dir){
        cin >> count;
        while (count--){
            // move head
            move_head(head,dir);
            if (tail_behind(head,tail)){
                move_tail(head,tail);
            }
        }
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
