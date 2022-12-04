#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif

void solve(){

    string line,temp;
    int elf1_start,elf1_end,elf2_start,elf2_end,i;
    int score = 0;
    while (true){
        getline(cin,line);
        if (!line.size()) break;
        // elf1_start
        i = 0; 
        temp = "";
        while (line[i] != '-'){
            temp.push_back(line[i]);
            ++i;
        }
        elf1_start = stoi(temp);
        ++i;
        // elf1_end
        temp = "";
        while (line[i] != ','){
            temp.push_back(line[i]);
            ++i;
        }
        elf1_end = stoi(temp);
        ++i;
        // elf2_start
        temp = "";
        while (line[i] != '-'){
            temp.push_back(line[i]);
            ++i;
        }
        elf2_start = stoi(temp);
        ++i;
        // elf2_end
        elf2_end = stoi(line.substr(i));

        if ((elf1_start <= elf2_start and elf2_end <= elf1_end) or
                (elf2_start <= elf1_start and elf1_end <= elf2_end)){
            ++score;
        }

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
