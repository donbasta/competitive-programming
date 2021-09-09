#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;
const ll MOD = 998244353;

int n;
ll fc[N + 5];
ll ifc[N + 5];

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

ll comb(int a, int b) {
    if (a < b || a < 0 || b < 0) return 0;
    ll ret = (fc[a] * ifc[a - b]) % MOD;
    ret = (ret * ifc[b]) % MOD;
    return ret;
}

void solve() {
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(ar.begin(), ar.end());
    if (ar[n - 1] - ar[n - 2] >= 2) {
        cout << 0 << '\n';
    } else {
        ll ans;
        int mx = ar[n - 1];
        int cnt = 0;
        int A = 0;
        for (int i = 0; i < n; i++) {
            if (ar[i] == mx) {
                cnt++;
            } else if (mx - ar[i] == 1) {
                A++;
            }
        }
        if (cnt > 1) {
            ans = fc[n];
        } else if (cnt == 1) {
            ll tmp = (comb(n, A + 1) * fc[A]) % MOD;
            // cerr << tmp << '\n';
            tmp = (tmp * fc[n - A - 1]) % MOD;
            ans = (fc[n] - tmp) % MOD;
            if (ans < 0) ans += MOD;
        }
        // cerr << fc[n] << '\n';
        cout << ans << '\n';
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    fc[0] = 1;
    for (int i = 1; i <= N; i++) {
        fc[i] = (fc[i - 1] * i) % MOD;
    }
    ifc[N] = fpow(fc[N], MOD - 2);
    for (int i = N - 1; i >= 0; i--) {
        ifc[i] = (ifc[i + 1] * (i + 1)) % MOD;
    }

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}