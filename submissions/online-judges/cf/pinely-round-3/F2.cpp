#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;
const ll MOD = 998244353;

void add(ll& x, ll y) {
    x = (x + y) % MOD;
}

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ar(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    for (int i = 1; i <= n; i++) {
        if (ar[i] > i) {
            cout << 0 << '\n';
            return;
        }
    }
    if (ar[n] != -1 && ar[n] != n) {
        cout << 0 << '\n';
        return;
    }
    if (ar[n] == -1) ar[n] = n;
    int L = 0;
    ll ans = 1;
    while (L < n) {
        int R = L + 1;
        while (ar[R] == -1) {
            R++;
        }
        int ki = ar[L], ka = ar[R];
        vector<map<ll, ll>> mp(R - L + 1);
        mp[0][ki] = 1;
        for (int i = 0; i < R - L; i++) {
            for (auto j : mp[i]) {
                if (j.first <= i + L + 1) {
                    add(mp[i + 1][j.first], mp[i][j.first]);
                }
                if (j.first + 1 <= i + L + 1) {
                    add(mp[i + 1][j.first + 1], 1ll * mp[i][j.first] * ((i + L - j.first) * 2 + 1) % MOD);
                }
                if (j.first + 2 <= i + L + 1) {
                    ll sq = 1ll * (i + L - j.first) * (i + L - j.first) % MOD;
                    add(mp[i + 1][j.first + 2], 1ll * mp[i][j.first] * sq % MOD);
                }
            }
        }
        // cerr << L << ' ' << R << ' ' << mp[R - L][ka] << '\n';
        ans = (ans * mp[R - L][ka]) % MOD;
        L = R;
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