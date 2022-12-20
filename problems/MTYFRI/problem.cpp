#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif

void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> motu;
    vector<int> tomu;
    int a;
    for (int i = 0; i < n; ++i){
        cin >> a;
        if (i%2 == 0)
            motu.push_back(a);
        else
            tomu.push_back(a);
    }
    sort(motu.begin(),motu.end(),greater<int>());
    sort(tomu.begin(),tomu.end());
    int tomu_score = 0,motu_score = 0;
    for (int i = 0; i < tomu.size(); ++i){
        if (k>0 and tomu[i] < motu[i])
            swap(motu[i],tomu[i]),--k;
        motu_score += motu[i];
        tomu_score += tomu[i];
    }
    if (tomu.size() < motu.size())
        motu_score += motu[motu.size()-1];
    if (motu_score < tomu_score)
        cout << "YES";
    else
        cout << "NO";

    
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
