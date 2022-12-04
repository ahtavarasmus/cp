#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif

void solve(){
    int n;
    cin >> n;
    int a[n];
    int d[n];
    for (int i = 0; i < n; ++i)cin >> a[i];
    for (int i = 0; i < n; ++i)cin >> d[i];

    int att,max_shield = -1;
    bool survives;
    for (int i = 0; i < n; ++i){
        att = 0;
        if (i==0){
            att += a[i+1];
            att += a[n-1];
        } else if (i == n-1){
            att += a[0];
            att += a[i-1];
        } else {
            att += a[i-1];
            att += a[i+1];
        }
        debug(att)
        if (d[i] > att){
            max_shield = max(max_shield,d[i]);
        }

    }
    cout << max_shield;

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
