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
    string s;
    string c = "codechef";
    unordered_map<char,int> soup;
    for (int i = 0; i < n; ++i){
        cin >> s;
        for (int i = 0; i < s.size(); ++i){
            debug(s[i])
            if (c.find(s[i]) != string::npos){
                soup[s[i]]++;
                debug(soup[s[i]])
            }
        }
    }
    
    int mn = INT_MAX;
    int cur;
    for (auto c : soup){
        cur = c.second;
        
        if (c.first =='c' or c.first =='e'){ 
            cur /= 2;
        }
        mn = min(cur,mn);
    }
    cout << mn;
    debug(mn)
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

