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
void _print(size_t t){cerr << t;}

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
    bool operator>(const Point &p) const {
        if (x != p.x) return x > p.x;
        return y > p.y;
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
/* -------------------------------------------------------------------------- */


void solve(){
    string snafu;
    ll fuel = 0,cur_fuel;
    ll place;
    while (cin >> snafu){
        place = 1;
        cur_fuel = 0;
        for (int i = snafu.size()-1; i > -1;--i){
            if (snafu[i] == '2') cur_fuel += 2*place;
            else if (snafu[i] == '1') cur_fuel += 1*place;
            else if (snafu[i] == '0') cur_fuel += 0*place;
            else if (snafu[i] == '-') cur_fuel += -1*place;
            else cur_fuel += -2*place;
            place *= 5;
        }
        fuel += cur_fuel;
    }
    cout << "fuel: " << fuel << endl;

    string dir = "up";
    ll cur,last_place;
    ll multiple;
    map<ll,ll> code;
    cur = 0;
    last_place = LLONG_MAX;
    bool keep_dir = false,found = false;
    while (true){
        if (last_place == 1) break;
        multiple = 0;
        place = 1;
        if (dir == "up"){
            keep_dir = false;
            while (cur+place*multiple < fuel){
                if (multiple < 2){
                    multiple++;
                } else {
                    if (place*5 == last_place) {
                        keep_dir = true;
                        break;
                    }
                    multiple = 0;
                    place *= 5;
                }
            }
            cur += multiple*place;
            code[place] = multiple;
            if (cur == fuel) {
                found = true;
                break;
            }
            last_place = place;
            debug(place)
            debug(cur)
            if (!keep_dir)
                dir = "down";
        } else {
            keep_dir = false;
            while (cur+place*multiple > fuel){
                if (multiple > -2){
                    multiple--;
                } else {
                    if (place*5 == last_place) {
                        keep_dir = true;
                        break;
                    }
                    multiple = 0;
                    place *= 5;
                }
            }
            cur += place*multiple;
            code[place] = multiple;
            if (cur == fuel){ 
                found = true;
                break;
            }
            last_place = place;
            debug(place)
            debug(cur)
            if (!keep_dir)
                dir = "up";
        }
        debug(fuel)
        debug(dir)
        debug(code)
        debug(code.size())
        debug(last_place)
        debug("hä")
        if (found) break;
    }
    debug(code.size())
    int map_size = code.size();
    ll non_zeros = 0;
    place = 1;
    snafu = "";
    ll oneup_max_place = max_element(code.begin(),code.end())->first*5;
    debug(code.size())
    while (place != oneup_max_place){
        if (code.contains(place)){
            debug(code[place])
            debug(place)
            if (code[place] == -2) snafu.push_back('=');
            if (code[place] == -1) snafu.push_back('-');
            if (code[place] == 0) snafu.push_back('0');
            if (code[place] == 1) snafu.push_back('1');
            if (code[place] == 2) snafu.push_back('2');
        } else {
            snafu.push_back('0');
        }
        place *= 5;
    }
    reverse(snafu.begin(),snafu.end());
    cout << "fuel in snafu: " << snafu;
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
