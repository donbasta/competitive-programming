#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<ll> t(n - 1), a(n), b(n), p(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> t[i];
        p[i + 1] = t[i] + p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int ptr = n - 1;
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        ll need = b[i];
        ptr = min(ptr, i - 1);
        while (a[i] < need) {
            if (ptr < 0) {
                cout << -1 << '\n';
                return;
            }
            ll kur = min(need - a[i], a[ptr]);
            a[ptr] -= kur;
            a[i] += kur;
            ans += kur * (p[i] - p[ptr]);
            if (a[i] == need) break;
            --ptr;
        }
    }
    cout << ans << '\n';
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