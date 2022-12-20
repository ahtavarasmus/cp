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
    int b[n];
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    vector<int> longest_subarray_lengths;
    longest_subarray_lengths.reserve(n);
    for (int i = 0; i < n; ++i){
        list<int> subarray = {a[i]};
        
        for (int j = i+1; j < n; ++j){
            if (a[j] * subarray.back() < 0)
                subarray.push_back(a[j]);
            else
                break;
        }
        longest_subarray_lengths.push_back(subarray.size());
    }
    for (int i = 0; i < longest_subarray_lengths.size(); ++i){
        cout << " "<< longest_subarray_lengths[i];
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
