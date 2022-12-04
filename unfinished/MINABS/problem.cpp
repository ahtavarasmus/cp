#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif

void solve(){
    map<char,int> m;        
    string s = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < s.size(); ++i){
        m[s[i]] = i+1;
    }
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    int c1,c2,inc,dec;
    int decs[n];
    int incs[n];
    int decsum = 0;
    int incsum = 0;
    for (int i = 1; i <= n; ++i){
        c1 = m[a[i]];
        c2 = m[b[i]];
        debug(c1)
        debug(c2)

        if (c1<=c2){
            inc = (c2-c1); 
            dec = (26-c2+c1);
        } else {
            inc = (26-c1+c2);
            dec = (c1-c2);
        }
        decs[i-1] = dec;
        incs[i-1] = inc;
        decsum += dec;
        incsum += inc;
        debug(decsum)
        debug(incsum)
    }
    debug("this")
    int dif = incsum-decsum;
    cout << dif;


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
