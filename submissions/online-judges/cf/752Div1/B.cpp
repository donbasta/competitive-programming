#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    ll x, y;
    cin >> x >> y;
    ll ans;
    if (x > y) {
        ans = x + y;
    } else if (x == y) {
        ans = x;
    } else {
        ll a = y / x;
        ll b = (y - a * x) / 2;
        ans = y - b;
    }
    assert (ans % x == y % ans);
    cout << ans << '\n';
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