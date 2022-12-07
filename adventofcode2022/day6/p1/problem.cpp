#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif

void solve(){
    string s;
    cin >> s;
    string tmp;
    map<char,int> dif;
    bool not_yet = false;
    int ans;
    for (int i = 0; i < s.size(); ++i){
        if (tmp.size() < 4){
            tmp.push_back(s[i]);
        } else {
            dif.clear();
            not_yet = false;
            for (int j = 0; j < 4; j++){
                if (dif[tmp[j]]){
                    not_yet = true;
                }
                dif[tmp[j]]++;
            }
            if (not_yet){
                tmp = tmp.substr(1,3)+s[i];
            } else {
                ans = i;
                break;
            }
        }
        
    }
    cout << ans;
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
    solve();
    cout << "\n";
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
