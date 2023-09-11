#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

ll lcm(ll x, ll y) {
    return (x / __gcd(x, y)) * y;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    int cnt = 1;
    ll L = b[0];
    ll G = a[0] * b[0];
    for (int i = 1; i < n; i++) {
        L = lcm(L, b[i]);
        G = __gcd(G, a[i] * b[i]);
        if (G % L != 0) {
            cnt++;
            L = b[i];
            G = a[i] * b[i];
        }
    }
    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}