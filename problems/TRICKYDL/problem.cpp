#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;



#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T,class V> void _print(pair<T,V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T,class V> void _print(map<T,V> v);
template <class T> void _print(multiset<T> v);
template <class T,class V> void _print(pair<T,V> p){cerr<<"(";_print(p.first);cerr<<", ";_print(p.second);cerr<<")";}
template <class T> void _print(vector<T> v){cerr<<"{ ";for(T i : v){_print(i);cerr<<" ";}cerr<<"}";}
template <class T> void _print(set<T> v){cerr<<"{ ";for (T i : v){_print(i);cerr<<" ";}cerr<<"}";}
template <class T> void _print(multiset<T> v){cerr<<"{ ";for (T i : v){_print(i);cerr<<" ";}cerr<<"}";}
template <class T,class V> void _print(map<T,V> v){cerr<<"{ ";for (auto i : v) {_print(i);cerr << " ";}cerr<<"}";}


void solve(){
    ll a; 
    cin >> a;
    ll sum_chef = 0,day = 0,d1 = 0,sum_max_chef = 0;
    while (sum_chef >= 0){
        sum_chef += (a-pow(2,day));
        day++;
        if (sum_chef > sum_max_chef){
            sum_max_chef = sum_chef;
            d1 = day;
        }
    }
    cout << day-1 << " " << d1;
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
