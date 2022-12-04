#include <iostream>
#include <unordered_map>
using namespace std;
void solve();
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
void solve()
{
    int n,num;
    cin >> n;
    unordered_map<int,int> m;
    for (int i = 0; i < n; i++){
        cin >> num;
        m[num]++;
    }
    int x = 0;
    int yes = 1;
    for (auto c : m){
        if (c.second > x){
            x = c.second;
            yes = 1;
        } else if (c.second == x){
            yes = 0;
        }
    }
    if (yes)
        cout << "yes";
    else
        cout << "no";

}
