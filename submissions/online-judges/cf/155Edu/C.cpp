#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const ll MOD = 998244353;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<ll> comp;
    int len = 1;
    char cur = s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] != cur) {
            comp.push_back(len);
            len = 1;
            cur = s[i];
        } else {
            len++;
        }
    }
    comp.push_back(len);
    int sz = comp.size();
    int ans = n - sz;
    ll cnt = 1;
    for (auto e : comp) {
        cnt = (cnt * e) % MOD;
    }
    for (int i = 1; i <= ans; i++) {
        cnt = (cnt * i) % MOD;
    }
    if (cnt < 0) cnt += MOD;
    cout << ans << ' ' << cnt << '\n';
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