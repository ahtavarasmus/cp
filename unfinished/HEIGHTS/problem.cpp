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
    long int num;
    for (int i = 0; i < n; ++i){
        cin >> num;
        m[num]++;
    }
    int m_size = m.size();
    int keys[m_size];
    int i = 0;
    for (auto c : m){
        keys[i] = c.first;
        ++i;
    }

    int count = 0;
    for (int i = 0,j=m_size-1; i <= j;--j, ++i){
        debug(keys[i])
        debug(keys[j])
        while (m[keys[i]] != 1) ++i;
        while (m[keys[j]] != 1)

    }
    debug("moi")

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
