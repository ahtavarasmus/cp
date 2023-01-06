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
    int n;
    cin >> n;
    int even_arr_sum = 0, odd_arr_sum = 0;
    vector<int> even_arr,odd_arr;
    for (int i = 1; i <= n; ++i){
        debug(i)
        if (i%2==0){
            even_arr.push_back(i);
            even_arr_sum += i;
            debug(even_arr)
        } else {
            odd_arr.push_back(i);
            odd_arr_sum += i;
            debug(odd_arr)
        }
    }
    debug(even_arr)
    debug(odd_arr)
    if (abs(odd_arr_sum-even_arr_sum)%2 == 0){
        cout << "YES" << endl;
        for (int i = 0; i < abs(odd_arr_sum-even_arr_sum)/2; ++i){
            swap(odd_arr[i],even_arr[i]);
        }
        for (int i = 0; i < n/2; ++i)
            cout << odd_arr[i] << " ";
        cout << endl;
        for (int i = 0; i < n/2; ++i)
            cout << even_arr[i] << " ";

    } else {
        cout << "NO";
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
  
    int t = 1;
    /*is Single Test case?*/ cin >> t;
    while (t--) {
        solve();
        cout << "\n";
    }
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
