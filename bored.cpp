#include <bits/stdc++.h>

using namespace std;



typedef long long ll;

typedef long double ld;

typedef string str;



ll oddSquares(ll n) {

    ll sum = 0;

    while(n > 0) {

        sum += (n * n);

        n -= 2;

    }

    return sum;

}



void solve() {

    ll n; cin >> n;

    cout << oddSquares(n) << endl;

}



int main() {

    ll t; cin >> t;

    while(t--) solve();

    return 0;

}
