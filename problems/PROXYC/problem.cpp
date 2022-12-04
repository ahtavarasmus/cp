#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif

void solve(){
    int d;
    cin >> d;
    string s;
    cin >> s;
    int pre = 0;
    for (int i = 0; i < d; ++i){
        if (s[i] == 'P')
            ++pre;
    }
    int goal = (d*3);
    if (goal%4 != 0){
        goal /= 4;
        ++goal;
    } else {
        goal /= 4;
    }
    debug(goal)
    debug(pre)
    if (pre >= goal){
        cout << "0";
        return;
    }
    int needed = goal-pre;
    debug(needed)
    
    for (int i = 2; i < (d-2) and (needed > 0); ++i){
        if ((s[i]=='A') && (s[i-2]=='P' || s[i-1]=='P') && 
                (s[i+1]=='P' || s[i+2]=='P')){
            --needed;
        }
        debug(needed)
    }
    if (needed != 0)
        cout << "-1";
    else
        cout << goal-pre;

    
        
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
  
    int t = 1;
    /*is Single Test case?*/ cin >> t;
    while (t--) {
        solve();
        cout << "\n";
    }
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
