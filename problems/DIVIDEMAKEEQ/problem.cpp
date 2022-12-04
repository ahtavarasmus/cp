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
    int mn = INT_MAX;
    for (int i= 0; i < n; ++i){
        cin >> a[i];
        if (a[i] < mn) mn = a[i];
    }
    // check if we are able to make every elem to mn elem
    bool no = false;
    int mins = 0;
    for (int i = 0; i < n; ++i){
        if (a[i] == mn){
            ++mins;
            continue;
        }
        if (a[i]%mn != 0){
            no = true;
            break;
        }
    }
    if (no){
        cout << n;
    } else {
        cout << n-mins;
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
