#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif

void solve(){
    string s;
    int calories = 0;
    int max_calories = 0;
    while (getline(cin,s)){
        if (s.size() == 0){
            cout << "calories: " << calories << endl;
            max_calories = max(max_calories,calories);
            calories = 0;
            cout << endl;
        } else {
            calories += stoi(s);
            cout << s << endl;
        }
    }
    cout << max_calories;

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
