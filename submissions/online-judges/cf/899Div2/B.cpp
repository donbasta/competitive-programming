#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> se(n);
    vector<vector<int>> in(50);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            --x;
            se[i].push_back(x);
            in[x].push_back(i);
        }
    }
    int ans = 0;
    for (int i = 0; i < 50; i++) {
        if (in[i].empty()) continue;
        vector<bool> cant(n);
        for (auto e : in[i]) cant[e] = true;
        set<int> tmp;
        for (int j = 0; j < n; j++) {
            if (cant[j]) continue;
            for (auto c : se[j]) tmp.insert(c);
        }
        ans = max(ans, (int)tmp.size());
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