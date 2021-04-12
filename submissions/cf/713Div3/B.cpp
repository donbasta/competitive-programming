#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<pair<int, int>> pos, ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '*') {
                pos.emplace_back(i, j);
            }
        }
    }
    int p = pos[0].first, q = pos[0].second, r = pos[1].first, ss = pos[1].second;
    if (p == r) {
        ans.emplace_back(p ? 0 : 1, q);
        ans.emplace_back(p ? 0 : 1, ss);
    } else if (q == ss) {
        ans.emplace_back(p, q ? 0 : 1);
        ans.emplace_back(r, q ? 0 : 1);
    } else {
        ans.emplace_back(p, ss);
        ans.emplace_back(r, q);
    }
    for (auto e : ans) {
        s[e.first][e.second] = '*';
    }
    for (int i = 0; i < n; i++) {
        cout << s[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}