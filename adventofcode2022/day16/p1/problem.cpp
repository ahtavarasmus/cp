#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif

struct valve {
    string name;
    int rate;
    int release_here;
    int time_left_here;
    set<string> lead_to;
};
typedef struct valve valve;

void parse(map<string,valve> &m)
{
    string line,valve_name,tmp,srate,stunnel;
    while (getline(cin,line)){
        if (line.empty()) break;
        istringstream data(line);
        data>>tmp>>valve_name>>tmp>>tmp>>srate>>tmp>>tmp>>tmp>>tmp;
        valve new_valve;
        new_valve.name = valve_name;
        while (data >> stunnel){
            stunnel = stunnel.substr(0,2);
            new_valve.lead_to.insert(stunnel);
        }
        new_valve.rate = stoi(srate.substr(5,srate.size()-6));
        new_valve.release_here = 0;
        new_valve.time_left_here = 0;
        m[valve_name] = new_valve;
    }
}


void solve(){
    map<string,valve> m; 
    parse(m);

    // with dijkstra maybe
    priority_queue<pair<int,string>> q;
    q.push({m["AA"].rate,"AA"});
    pair<int,string> cur;
    while (!q.empty()){
        cur = q.top();
        string valve_name = cur.second;
        int cur_release_here = cur.first;
        q.pop();
        for (auto &p : m[valve_name].lead_to){
            if (m[valve_name].time_left_here+1)
        }

    }

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
