#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif


struct monkey {
    int id;
    list<long long int> items;
    string op,by_what;
    int test_div;
    pair<int,int> true_false_monkey;
    long long int inspected;
};
typedef struct monkey monkey;


void test_monkey(const monkey &m)
{
    debug(m.id)
    debug(m.items.size())
    debug(m.op)
    debug(m.by_what)
    debug(m.test_div)
    debug(m.true_false_monkey.first)
    debug(m.true_false_monkey.second)
    debug(" ")
}

void parse_input(auto &monkeys)
{
    string line,r;
    for (int m = 0; m < 8; m++){
        // header
        getline(cin,line);
        // items
        getline(cin,line);
        istringstream items(line);
        items >> r >> r;
        monkey mon;
        mon.id = m;
        while (items >> r){mon.items.push_back(stoi(r.substr(0,2)));}
        
        // operation
        getline(cin,line);
        istringstream op(line);
        string by_what;
        op >> r >> r >> r >> r >> r >> by_what;
        mon.op = r;
        mon.by_what = by_what;

        // test
        getline(cin,line);
        istringstream test(line);
        test >> r >> r >> r >> r;
        mon.test_div = stoi(r);
        // true
        getline(cin,line);
        istringstream tru(line);
        tru >> r >> r >> r >> r >> r >> r;
        mon.true_false_monkey.first = stoi(r);
        // false 
        getline(cin,line);
        istringstream fals(line);
        fals >> r >> r >> r >> r >> r >> r;
        mon.true_false_monkey.second = stoi(r);
        getline(cin,line);
        mon.inspected = 0;

        // add to map
        monkeys[m] = mon;

 
    }
}

void test_items(auto &monkey)
{
    debug(monkey.items.size())
    for (auto item : monkey.items)
        debug(item)
}

void test_monkeys(auto &monkeys)
{
    for (int monkey = 0; monkey < 8; ++monkey){
        debug(monkey)
        debug(monkeys[monkey].inspected)
    }
}

void solve(){
    map<int,monkey> monkeys;
    parse_input(monkeys);

    test_monkeys(monkeys);

    long long int MaxDivisor = 1;
    for (const auto &monkey : monkeys){
        MaxDivisor *= monkey.second.test_div;
    }
    debug(MaxDivisor)

    for (long long int round = 0; round < 10000; ++round){
        //test_monkeys(monkeys);
        for (int m = 0; m < 8; ++m){

            int item_count = monkeys[m].items.size();
            monkeys[m].inspected += item_count;
            for (int item = 0; item < item_count; ++item){
                long long int worry = monkeys[m].items.front();
                long long int by_what;
                monkeys[m].items.pop_front();
                if (monkeys[m].by_what == "old") by_what = worry;
                else by_what = stoi(monkeys[m].by_what);
                if (monkeys[m].op == "+") worry += by_what;
                else worry *= by_what;

                worry %= MaxDivisor;
                if (worry % monkeys[m].test_div == 0){
                    monkeys[monkeys[m].true_false_monkey.first].items.push_back(worry);
                } else {
                    monkeys[monkeys[m].true_false_monkey.second].items.push_back(worry);
                }
            }
        }
        debug("ROUND")
        debug(round)
        test_monkeys(monkeys);
    }
    monkey first,second;
    first.inspected = 0,second.inspected = 0;
    for (auto monkey : monkeys){
        debug(monkey.second.id)
        debug(monkey.second.inspected)
        if (monkey.second.inspected > first.inspected){
            second = first;
            first = monkey.second;
        } else if (monkey.second.inspected > second.inspected){
            second = monkey.second;
        }
    }
    debug(first.id)
    debug(second.id)
    long long int monkey_business = first.inspected * second.inspected;
    debug(monkey_business)
    cout << monkey_business;
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
