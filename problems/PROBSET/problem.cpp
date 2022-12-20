#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif

void solve(){
    int n,m;
    cin >> n >> m;
    debug("new")
    string intend,solution;
    bool invalid = false,weak = false;
    for (int i = 0; i < n; ++i){
        cin >> intend >> solution;
        if (intend == "correct"){
            for (int j = 0; j < m; ++j){
                if (solution[j] == '0'){
                    invalid = true;
                }
            }
        } else {
            debug(i)
            bool failed_some = false;
            debug(solution)
            for (int j = 0; j < m; ++j){
                if (solution[j] == '0')
                    failed_some = true;
            }
            if (!failed_some){
                weak = true;
            }
            debug(weak)
        }
    }
    if (invalid)
        cout << "INVALID";
    else if (weak)
        cout << "WEAK";
    else
        cout << "FINE";
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
