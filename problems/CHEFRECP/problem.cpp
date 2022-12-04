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
    map<int,int> m;
    int a[n];
    debug("HEHEH")
    for (int i = 0; i < n; ++i){ 
        cin >> a[i];
    }

    int r;
    int last_one = a[0];
    for (int i = 0; i < n; ++i){
        if (m.find(a[i])==m.end()){
            m[a[i]]++;
        } else {
            if (last_one == a[i]){
                m[a[i]]++;
                continue;
            }
            cout << "NO";
            return;
        }
        last_one = a[i];
    }
    set<int> quantities;
    for (auto p : m){
        if (quantities.find(p.second) == quantities.end()){
            quantities.insert(p.second);
        } else {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
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
