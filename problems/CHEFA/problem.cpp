#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif

void solve(){
    vector<long int> piles;
    int n,pile;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> pile;
        piles.push_back(pile);
    }
    sort(piles.begin(),piles.end());
    long long int stones = 0;
    for (int i = n-1; i > -1; i -= 2){
        stones += piles[i];
    }
    cout << stones;
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
