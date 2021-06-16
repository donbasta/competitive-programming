#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const int N = 1e5;

int n, k;
ll fc[N + 5], ifc[N + 5];
ll pre[N + 5];
int a[N + 5];
string s;

ll fpow(ll a, ll b, ll c) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return ret;
}

void init_fac() {
    fc[0] = 1;
    for (int i = 1; i <= N; i++) { fc[i] = (fc[i - 1] * i) % MOD; }
    ifc[N] = fpow(fc[N], MOD - 2, MOD);
    for (int i = N - 1; i >= 0; i--) { ifc[i] = (ifc[i + 1] * (i + 1)) % MOD; }
}

ll C(ll a, ll b) {
    if (a < 0 || b < 0 || a < b) return 0;
    ll ret = (fc[a] * ifc[a - b]) % MOD;
    ret = (ret * ifc[b]) % MOD;
    return ret;
}

void solve() {
    init_fac();
    cin >> n >> k;
    cin >> s;
    for (int i = 1; i <= n; i++) { a[i] = (int) (s[i - 1] - '0'); }
    if (n == 1) {
        cout << a[n] << '\n';
        return;
    }
    ll inv10 = fpow(10, MOD - 2, MOD);
    ll p = fpow(10, n - 2, MOD);
    ll ans = (C(n - 1, k) * a[n]) % MOD;
    for (int i = n - 2; i >= 0; i--) {
        pre[i] = (pre[i + 1] + C(i, k - 1) * fpow(inv10, i, MOD)) % MOD;
    }
    for (int i = 1; i <= n - 1; i++) {
        ll tmp = p * a[i] % MOD;
        ll A = p * a[i] % MOD;
        ll B = (pre[i - 1] + C(i - 1, k) * (i >= 2 ? fpow(inv10, i - 2, MOD) : 10)) % MOD;
        ans = (ans + A * B) % MOD;
    }
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