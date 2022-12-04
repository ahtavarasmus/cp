#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif

void solve(){
    map<string,int> rpc;
    // ans is what i need to play for losing it or tieing or winning
    map<string,string> ans;

    ans["AX"] = "AZ"; 
    ans["AY"] = "AX";
    ans["AZ"] = "AY";
    ans["BX"] = "BX";
    ans["BY"] = "BY";
    ans["BZ"] = "BZ";
    ans["CX"] = "CY";
    ans["CY"] = "CZ";
    ans["CZ"] = "CX";


    rpc["AX"] = 1+3;
    rpc["AY"] = 2+6;
    rpc["AZ"] = 3+0;
    rpc["BX"] = 1+0;
    rpc["BY"] = 2+3;
    rpc["BZ"] = 3+6;
    rpc["CX"] = 1+6;
    rpc["CY"] = 2+0;
    rpc["CZ"] = 3+3;

    string key,line;
    string op,me;
    int score = 0;
    while (true){
        getline(cin,line);
        if (line.size() == 0) break;

        key = line.substr(0,1)+line.substr(2,1);
        score += rpc[ans[key]];
    }
    cout << score << endl;
    
    
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
