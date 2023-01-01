#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif

void solve(){
    map<int,int> hotel;
    int n,time;
    cin >> n;

    int max_time = INT_MIN,min_time = INT_MAX;

    int a[n];
    // time,count
    map<int,int> quests;
    for (int i = 0;  i < n; ++i){
        cin >> time;
        min_time = min(min_time,time);
        quests[time]++;
    }
    for (int i = 0; i < n; ++i){
        cin >> time;
        max_time = max(max_time,time);
        quests[time]--;
    }
    int count = 0;
    int max_count = 0;
    for (int i = min_time; i <= max_time; ++i){
        count += quests[i];
        max_count = max(max_count,count);
    }
    cout << max_count;

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
