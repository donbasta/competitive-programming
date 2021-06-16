#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 998244353;

ll n, m;
const int N = 20;
const int M = 5e4;

int ar[N + 5][M + 5];

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ar[i][j];
        }
    }
    ll nfac = 1;
    ll tmp = 0;
    for (int i = 1; i <= n; i++) { nfac = nfac * i % MOD; }
    for (int i = 0; i < m; i++) {
        vector<int> ve;
        for (int j = 0; j < n; j++) {
            ve.emplace_back(ar[j][i]);
        }
        sort(ve.begin(), ve.end());
        ll not_in = 1;
        for (int i = 0; i < n; i++) {
            ll sz = ve[i] - (i + 1);
            if (sz <= 0) {
                not_in = 0;
                break;
            }
            // sz = min(sz, n - i);
            not_in = not_in * sz % MOD;
        }
        tmp = (tmp + not_in) % MOD;
    }
    // tmp = tmp * fpow(nfac, MOD - 2) % MOD;
    ll ans = (m - tmp * fpow(nfac, MOD - 2)) % MOD;
    if (ans < 0) ans += MOD;
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