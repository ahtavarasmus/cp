#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif

void solve(){
    int n,k,l;
    cin >> n >> k >> l;
    int a[n];
    int maxi = 0;
    cin >> a[0];
    for (int i = 1; i < n; ++i){
        cin >> a[i];
        if (a[i] > a[maxi])
            maxi = i;
    }
    for (int i = 0; i < n; ++i)
        debug(a[i])
    if (maxi == n-1){
        cout << "yes";
        return;
    }
    debug(maxi)
    debug(a[maxi])
    debug(a[n-1])

    while (l-- > 1){
        a[n-1] += k;
    }
    debug(a[n-1])
    if (a[maxi] < a[n-1]){
        cout << "yes";
    } else {
        cout << "no";
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
  
    int t = 1;
    /*is Single Test case?*/ cin >> t;
    while (t--) {
        solve();
        cout << "\n";
    }
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
