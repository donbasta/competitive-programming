#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    ll n, k, d;
    cin >> n >> k >> d;
    vector<ll> ar(n + 1), b(k + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> b[i];
    }
    ll ans = 0;
    int idx = 1;
    for (int i = 1; i <= min(d, 2 * n + 5); i++) {
        ll cek = 0;
        for (int j = 1; j <= n; j++) {
            cek += ar[j] == j;
        }
        ans = max(ans, cek + (d - i) / 2);
        for (int j = 1; j <= b[idx]; j++) {
            ar[j]++;
        }
        idx = (idx % k) + 1;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}