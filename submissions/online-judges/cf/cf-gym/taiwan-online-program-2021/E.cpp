#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MX = 1e18;

void solve() {
    ll p, q;
    cin >> p >> q;
    // p <= q * d^5
    ll a = (p + q - 1) / q;
    ll d = 1;
    ll loss = 0;
    for (;;d++){
        ll temp = d * d * d * d * d;
        if (a <= temp) break;
        else {
            loss += (q * temp - p);
        }
    }
    ll c = loss + p * (d - 1);
    ll x = p - loss;
    ll l = d, r = MX;
    const auto F = [&](ll x) -> ld {

    }
    ll ans = MX;
    while (l <= r) {
        ll mid = (l + r) / 2;
        ld log_profit = F(mid);
        if (log_profit >= ld(99)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}