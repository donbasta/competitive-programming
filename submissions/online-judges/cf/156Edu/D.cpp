#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int MOD = 998244353;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

ll inv(ll a) {
    return fpow(a, MOD - 2);
}

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    ll cur = 1;
    bool nol = false;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '?') {
            if (i == 0) {
                nol = true;
            } else {
                cur = (cur * i) % MOD;
            }
        }
    }
    vector<ll> ans;
    if (nol)
        ans.push_back(0);
    else
        ans.push_back(cur);
    for (int i = 0; i < m; i++) {
        int pos;
        char c;
        cin >> pos >> c;
        pos--;
        if (pos == 0) {
            if (s[pos] == '?') nol = false;
            s[pos] = c;
            if (s[pos] == '?') nol = true;
        } else {
            if (s[pos] == '?') cur = (cur * inv(pos)) % MOD;
            s[pos] = c;
            if (s[pos] == '?') cur = (cur * pos) % MOD;
        }
        if (nol)
            ans.push_back(0);
        else
            ans.push_back(cur);
    }
    for (auto e : ans) {
        cout << e << '\n';
    }
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