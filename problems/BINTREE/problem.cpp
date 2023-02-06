#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif

int msb_bit(int n){
    int k = (int)(log2(n));
    return (int)(pow(2,k));
}

void solve(){
    int i,j;    
    cin >> i >> j;
    debug("s")
    debug(i)
    debug(j)
    if (i == j){
        cout << 0;
        return;
    }
    // always put i as a bigger one
    int t;
    if (i < j){
        t = j,j = i,i = t;
    }
    debug("s")
    debug(i)
    debug(j)
    int j_league = msb_bit(j);
    int i_league = msb_bit(i);
    int steps = 0;
    // first count how many steps to go up until both are
    // in the same value range (same msb bit)
    while (msb_bit(i) != j_league){
        i /= 2;
        steps++;
    }
    debug(steps)
    debug("s")
    debug(i)
    debug(j)

    // round down any odd numbers
    int sideways = (abs(i-j)/2)*2;
    // if not already same, the minimum is 2 steps to side one
    if (i != j) sideways += 2;
    debug(sideways)
    steps += sideways;

    debug(steps)
    debug("e")
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
