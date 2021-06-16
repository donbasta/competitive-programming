#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

inline ll ceil(ll x, ll y) {
    return (x + y - 1) / y;
}

void solve() {
    ll p, a, b, c;
    cin >> p >> a >> b >> c;
    ll x = min({a * ceil(p, a), b * ceil(p, b), c * ceil(p, c)});
    cout << x - p << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}