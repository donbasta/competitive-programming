#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const int N = 2e5;

ll fc[N + 10], ifc[N + 10];
int n;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

void init_fac() {
    fc[0] = 1;
    for (int i = 1; i <= N + 5; i++) {
        fc[i] = (fc[i - 1] * i) % MOD;
    }
    ifc[N + 5] = fpow(fc[N + 5], MOD - 2);
    for (int i = N + 4; i >= 0; i--) {
        ifc[i] = (ifc[i + 1] * (i + 1)) % MOD;
    }
}

ll C(ll a, ll b) {
    if (a < b || a < 0 || b < 0) return 0;
    ll ret = (fc[a] * ifc[a - b]) % MOD;
    ret = (ret * ifc[b]) % MOD;
    return ret;
}

void solve() {
    cin >> n;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort (ar.begin(), ar.end());
    reverse (ar.begin(), ar.end());
    int a = 1, b = n;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll tmp = 0;
        if (i & 1) {
            tmp = C(n + 1, b) - 1;
            b--;
        } else {
            tmp = C(n + 1, a) - 1;
            a++;
        }
        tmp = (tmp * ar[i]) % MOD;
        ans = (ans + tmp) % MOD;
    }
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    init_fac();

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}