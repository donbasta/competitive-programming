#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<pair<char, int>> ve;
    int s0 = 0, s1 = 0;
    char cur = s[0];
    if (cur == '0')
        s0++;
    else
        s1++;
    int len = 1;
    for (int i = 1; i < n; i++) {
        s0 += s[i] == '0', s1 += s[i] == '1';
        if (s[i] == cur)
            len++;
        else {
            ve.emplace_back(cur, len);
            cur = s[i];
            len = 1;
        }
    }
    ve.emplace_back(cur, len);
    int sz = ve.size();
    int p0 = 0, p1 = 0;
    ll ans = 1e18;
    ll lmao = 1e12;
    for (int i = 0; i <= sz; i++) {
        int ol = p1, zr = s0 - p0;
        ll hihi = (lmao + 1) * (ol + zr);
        ans = min(ans, hihi);
        if (i >= 1 && ve[i - 1].first == '0' && ve[i - 1].second == 1) {
            if (i >= 2) {
                ans = min(ans, hihi - ve[i - 2].second);
            }
        }
        if (ve[i].first == '1' && ve[i].second == 1) {
            if (i + 1 < sz) {
                ans = min(ans, hihi - ve[i + 1].second);
            }
        }
        if (i < sz) {
            if (ve[i].first == '0')
                p0 += ve[i].second;
            else
                p1 += ve[i].second;
        }
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
        solve();
    }

    return 0;
}