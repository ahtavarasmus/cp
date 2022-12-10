#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif

void update_sum(int reg,int cycle,int &sum,set<int> &cycles)
{
    if (cycles.contains(cycle)){
        sum += reg*cycle;
    }
}

void solve(){
    string signal;
    int v,cycle = 0;
    set<int> cycles;
    cycles.insert(20);
    cycles.insert(60);
    cycles.insert(100);
    cycles.insert(140);
    cycles.insert(180);
    cycles.insert(220);

    int sum = 0;
    int reg = 1;
    while (cin >> signal){
        if (signal == "addx"){
            cin >> v;
            cycle++;
            update_sum(reg,cycle,sum,cycles);
            cycle++;
            update_sum(reg,cycle,sum,cycles);
            reg += v;
        } else {
            cycle++;
            update_sum(reg,cycle,sum,cycles);
        }
    }
    cout << sum;
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
