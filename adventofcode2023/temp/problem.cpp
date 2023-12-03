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

struct Point {
    int y,x;
    Point() : y(0),x(0) {};
    Point(const int& y,const int& x) : y(y),x(x) {};
    Point(const Point& other){x = other.x,y = other.y;};

    bool operator<(const Point &p) const {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }
    bool operator==(const Point &p) const {
        return (x == p.x) and (y == p.y);
    };
    Point& operator=(const Point& other){
        y = other.y;
        x = other.x;
        return *this;
    };
    size_t operator()(const Point& pointToHash) const noexcept {
        size_t hash = pointToHash.x + 10*pointToHash.y;
        return hash;
    };
};
namespace std {
    template<> struct hash<Point>{std::size_t operator()(const Point& p) const noexcept {
            return p(p);}};
}


void solve(){

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
