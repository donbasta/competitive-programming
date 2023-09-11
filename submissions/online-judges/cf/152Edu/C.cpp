#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

ll fpow(ll a, ll b, ll mod) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<ll> A(n), B(n);
    vector<int> pre(n);
    pre[0] = s[0] == '1';
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + (s[i] == '1');
    }
    A[0] = (s[0] - '0'), B[0] = (s[0] - '0');
    ll pw_1 = 2, pw_2 = 2;

    int mod_1 = 1e9 + 7, mod_2 = 1e9 + 9;
    for (int i = 1; i < n; i++) {
        int dig = s[i] - '0';
        A[i] = (A[i - 1] + (1ll * dig * pw_1)) % mod_1;
        pw_1 = (pw_1 * 2) % mod_1;
    }
    for (int i = 1; i < n; i++) {
        int dig = s[i] - '0';
        B[i] = (B[i - 1] + (1ll * dig * pw_2)) % mod_2;
        pw_2 = (pw_2 * 2) % mod_2;
    }

    set<pair<ll, ll>> se;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        ll tmp_1 = A[n - 1], tmp_2 = B[n - 1];
        int cnt = pre[r] - (l ? pre[l - 1] : 0);

        tmp_1 = (tmp_1 - A[r]) % mod_1;
        tmp_1 = (tmp_1 + (l ? A[l - 1] : 0)) % mod_1;
        ll AA = (fpow(2, r + 1, mod_1) - fpow(2, r + 1 - cnt, mod_1)) % mod_1;
        tmp_1 = (tmp_1 + AA) % mod_1;
        if (tmp_1 < 0) tmp_1 += mod_1;

        tmp_2 = (tmp_2 - B[r]) % mod_2;
        tmp_2 = (tmp_2 + (l ? B[l - 1] : 0)) % mod_2;
        ll BB = (fpow(2, r + 1, mod_2) - fpow(2, r + 1 - cnt, mod_2)) % mod_2;
        tmp_2 = (tmp_2 + BB) % mod_2;
        if (tmp_2 < 0) tmp_2 += mod_2;

        se.insert(make_pair(tmp_1, tmp_2));
    }

    cout << se.size() << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}