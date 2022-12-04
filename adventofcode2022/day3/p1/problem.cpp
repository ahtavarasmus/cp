#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif

void solve(){
    string alp = "abcdefghijklmnopqrstuvwxyz";
    map<char,int> m;
    for (int i = 1; i < 27; ++i){
        m[alp[i-1]] = i;
        debug(alp[i-1])
        debug(i)
    }

    string line,last_half;
    int len,mid,sum = 0;
    char dub;
    while (true){
        getline(cin,line);
        len = line.size();
        if (!len) break;

                
        mid = len/2;
        last_half = line.substr(mid,mid);
        for (int i = 0; i < mid; ++i){
            if (last_half.find(line[i]) != string::npos){
                dub = line[i];
                break;
            }
        }
        debug(dub)
        int score;
        if (isupper(dub)){
            score = m[tolower(dub)]+26;
            debug(score)
        } else {
            score = m[dub];
            debug(score)
        }

        sum += score;
    }
    cout << sum << endl;

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
