#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    vector<vector<int>> pos(k);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        pos[c[i] - 1].push_back(i);
    }
    int ans = 2e9;
    for (int i = 0; i < k; i++) {
        if (pos[i].empty()) continue;
        vector<int> tmp;
        tmp.push_back(pos[i][0]);
        for (int j = 1; j < pos[i].size(); j++) {
            tmp.push_back(pos[i][j] - pos[i][j - 1] - 1);
        }
        tmp.push_back(n - 1 - pos[i].back());
        sort(tmp.begin(), tmp.end());
        int lmao = tmp.back() / 2;
        if (tmp.size() > 1) lmao = max(lmao, tmp[tmp.size() - 2]);
        ans = min(ans, lmao);
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