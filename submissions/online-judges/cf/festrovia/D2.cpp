#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<pair<int, int>> ve;
    vector<int> cnt(2);
    cnt[s[0] - '0']++;
    for (int i = 1; i < n; i++) {
        if (s[i] < s[i - 1]) {
            ve.emplace_back(cnt[0], cnt[1]);
            cnt[0] = 1, cnt[1] = 0;
        } else {
            cnt[s[i] - '0']++;
        }
    }
    ve.emplace_back(cnt[0], cnt[1]);
    int sz = ve.size();
    vector<pair<int, int>> ret;
    ret.emplace_back(ve.back().first + ve.back().second, 0);
    int tmp = ve.back().first;
    for (int i = sz - 2; i >= 0; i--) {
        int a = ve[i].first, b = ve[i].second;
        int q = min(b, tmp);
        int p = a + b - q;
        ret.emplace_back(p, q);
        tmp += ve[i].first;
        tmp -= q;
    }
    reverse(ret.begin(), ret.end());
    string ans;
    for (auto e : ret) {
        for (int i = 0; i < e.first; i++) ans.push_back('0');
        for (int i = 0; i < e.second; i++) ans.push_back('1');
    }
    cout << ans << '\n';
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