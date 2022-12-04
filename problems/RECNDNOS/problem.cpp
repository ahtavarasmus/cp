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
    set<int> uni;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        uni.insert(a[i]);
    }
    int cur_count = 0;
    int max_count = 0;
    int max_num;
    bool took_last_one;
    for (auto c : uni){
        cur_count = 0;
        took_last_one = false;
        debug(c)
        for (int i = 0; i < n; ++i){
            debug(a[i])
            debug(took_last_one)
            if (a[i] == c){
                debug("INSIDE")
                if (!took_last_one){
                    ++cur_count;
                    took_last_one = true;
                    debug(cur_count)
                    continue;
                }
            }
            took_last_one = false;
        }
        if (cur_count > max_count){
            max_count = cur_count;
            max_num = c;
        }
        
        debug(max_count)
    }
    debug("HHE")
    cout << max_num;


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
