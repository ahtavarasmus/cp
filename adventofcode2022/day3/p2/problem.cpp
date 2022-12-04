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
    for (int i = 1; i < 27; ++i) m[alp[i-1]] = i;

    string elf1,elf2,elf3;
    int len,mid,sum = 0;
    int elf1_size;
    char badge;
    while (true){
        getline(cin,elf1);
        elf1_size = elf1.size();
        if (!elf1_size) break;
        getline(cin,elf2);
        getline(cin,elf3);


        
        for (int i = 0; i < elf1_size; ++i){
            if (elf2.find(elf1[i]) != string::npos and 
                    elf3.find(elf1[i]) != string::npos){
                badge = elf1[i];  
                break;
            }
        }

        int score;
        if (isupper(badge)){
            score = m[tolower(badge)]+26;
            debug(score)
        } else {
            score = m[badge];
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
