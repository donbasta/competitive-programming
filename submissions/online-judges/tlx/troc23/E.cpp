#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll f(ll a) {
    if (a & 1) {
        return (a / 2) - 1;
    }
    return a / 2;
}

ll g(ll a, ll b) {
    return ((a / 2) - 2) * ((b / 2) - 1);
}

ll h(ll m, ll n) {
    ll ret = g(m, n);
    if (n % 6 == 0) {
        ret += (n / 2);
    } else {
        ret += ((n - 9) / 2);
    }
    return ret;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    if (n > m) swap(n, m);
    if (n == 1) {
        cout << -1 << '\n';
        return;
    }
    if ((n & 1) && (m & 1)) {
        if ((n == 3) || ((n * m) % 3 != 0)) {
            cout << -1 << '\n';
        } else {
            ll ans = -1;
            if (n % 3 == 0 && m % 3 == 0) {
                ans = max(h(n, m), h(m, n));
            } else if (n % 3 == 0) {
                ans = h(m, n);
            } else if (m % 3 == 0) {
                ans = h(n, m);
            }
            cout << ans << '\n';
        }
    } else {
        ll ans = -1;
        if (n % 2 == 0 && m % 2 == 0) {
            ans = (n / 2) * (m / 2);
        } else if (n % 2 == 0) {
            
        }
        cout << ans << '\n';
    }
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