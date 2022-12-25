#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif

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
