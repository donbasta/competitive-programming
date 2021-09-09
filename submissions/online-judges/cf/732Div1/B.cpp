#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e5;
const ll MOD = 998244353;

ll fc[2 * N + 5], ifc[2 * N + 5];

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) { ret = (ret * a) % MOD; }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

inline ll inv(ll a) { return fpow(a, MOD - 2); }

void init_fac() {
    fc[0] = 1;
    for(int i = 1; i <= N; i++) {
        fc[i] = (fc[i - 1] * i) % MOD;
    }
    ifc[N] = inv(fc[N]);
    for(int i = N - 1; i >= 0; i--) {
        ifc[i] = (ifc[i + 1] * (i + 1)) % MOD;
    }
}

ll C(ll a, ll b) {
    if (a < b || a < 0 || b < 0) return 0;
    ll ret = fc[a];
    ret = (ret * ifc[b]) % MOD;
    ret = (ret * ifc[a - b]) % MOD;
    return ret;
}

int n;
string s;

void solve() {
    cin >> n >> s;
    bool ada = false;
    int odd = 0, even = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '1' && s[i + 1] == '1') {
            ada = true;
            break;
        }
    }
    if (!ada) {
        cout << 1 << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (i & 1) odd++;
            else even++;
        }
    }
    ans =  (C((n + 1) / 2, even) * C(n / 2, odd)) % MOD;
    ans = (ans - ) % MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    init_fac();

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}