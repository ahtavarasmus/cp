#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif

void solve(){
    string line;
    int len,stack_num;
    map<int,deque<char> > stacks;
    // reading stacks
    while (true){
        getline(cin,line);
        len = line.size();
        if (!len) break;
        stack_num = 1;
        for (int i = 0; i < len; ++i){
            if (line[i] == '['){
                debug(line[i+1])
                stacks[stack_num].push_back(line[i+1]);
            } 
            ++stack_num;
            i += 3;
        }
        debug(line)
    }
    debug("HAHAHAHAHHAAHHAHAHAHAHHAHHAAHHAHAHAHAH")


    // reading moves
    string com;
    int count,from,to;
    stack<char> tmp;
    char a,b;
    while (true){
        getline(cin,line);
        len = line.size();
        if (!len) break;
        istringstream linestream(line);
        linestream >> com >> count >> com >> from >> com >> to;

        while (count--){
            tmp.push(stacks[from].front());
            stacks[from].pop_front();

        }
        while (!tmp.empty()){
            stacks[to].push_front(tmp.top());
            tmp.pop();
        }
    }
    string message;
    for (auto tops : stacks){
        message.push_back(tops.second.front());
    }
    cout << message;
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
