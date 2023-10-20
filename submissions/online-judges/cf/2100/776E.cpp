#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    ll n, k;
    cin >> n >> k;
    ll now = 0;
    const ll mod = 1e9 + 7;
    while (true) {
        ll cn = n;
        ll phi = n;
        for (ll i = 2; i * i <= cn; i++) {
            if (cn % i != 0) continue;
            while (cn % i == 0) cn /= i;
            phi = phi / i * (i - 1);
        }
        if (cn > 1) phi = phi / cn * (cn - 1);
        now += 2;
        if (k <= now) {
            phi %= mod;
            cout << phi << '\n';
            return;
        } else if (phi == 1) {
            cout << 1 << '\n';
            return;
        }
        n = phi;
    }
    assert(false);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}