#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif

void solve(){
    int n,u,d;        
    cin >> n >> u >> d;
    int a[n];
    int maxi = 0;
    int big_jump_idx;
    bool big_jump_used = false;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        if (i != 0){
            if (!big_jump_used && (a[i-1]-a[i]) > d){
                big_jump_idx = i-1;
                big_jump_used = true;
            }
        }
    }
    big_jump_used = false;
    int trip = 1;
    for (int i = 1; i < n; ++i){
        if (a[i-1] < a[i]){
            if ((a[i]-a[i-1]) > u)
                break;
            
        } else if (a[i-1] > a[i]){
            if ((a[i-1]-a[i]) > d){
                if (!big_jump_used)
                    big_jump_used = true;
                else
                    break;
            }
        }
        ++trip;
    }
    cout << trip;



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
