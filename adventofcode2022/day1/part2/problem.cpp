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
    int top_three;
    int first = 0;
    int second = 0;
    int third = 0;
    while (getline(cin,s)){
        if (s.size() == 0){
            if (calories > first){
                third = second;
                second = first;
                first = calories;
            } else if (calories > second){
                third = second;
                second = calories;
            } else if (calories > third){
                third = calories;
            }
            calories = 0;
        } else {
            calories += stoi(s);
            
        }
    }
    debug(first)
    debug(second)
    debug(third)
    top_three = first+second+third;
    cout << top_three;

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
