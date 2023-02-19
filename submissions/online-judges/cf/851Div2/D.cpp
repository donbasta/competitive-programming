#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const ll MOD = 1e9 + 7;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

ll F(int x, int y) {
    if (x > y) assert(false);
    ll A = fpow(2LL, y + 1);
    ll B = fpow(2LL, x);
    ll ret = (A - B) % MOD;
    if (ret < 0) ret += MOD;
    return ret;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    int lol = ar[0];
    for (int i = 0; i < n; i++) {
        ar[i] -= lol;
    }

    ll ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            ll jarak = ar[j] - ar[i];
            if (j + 1 < n && (ar[j + 1] - ar[j] >= jarak)) continue;
            if (i > 0 && (ar[i] - ar[i - 1] > jarak)) continue;
            ll cekKanan = lower_bound(ar.begin() + j + 1, ar.end(), jarak + ar[j]) - ar.begin();
            ll cntKanan = F(n - cekKanan, n - j - 2);
            ll cekKiri = lower_bound(ar.begin(), ar.begin() + i, ar[i] - jarak) - ar.begin();
            --cekKiri;
            ll cntKiri = F(cekKiri + 1, i - 1);
            ll cnt = (cntKanan * cntKiri) % MOD;
            // cout << i << ' ' << j << ' ' << cekKiri << ' ' << cekKanan << ' ' << cntKiri << ' ' << cntKanan << '\n';
            ans = (ans + cnt) % MOD;
        }
    }
    ans %= MOD;
    ans = (ans + fpow(2LL, n)) % MOD;
    ans = (ans - n - 1) % MOD;
    ans %= MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
    return;
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