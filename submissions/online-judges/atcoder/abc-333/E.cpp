#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<pair<int, int>> ve;
    vector<vector<int>> pos(n + 1);
    vector<bool> take(n);
    for (int i = 0; i < n; i++) {
        int t, x;
        cin >> t >> x;
        ve.emplace_back(t, x);
        if (t == 1) {
            pos[x].push_back(i);
        }
    }
    vector<int> cur(n + 1);
    for (int i = 1; i <= n; i++) cur[i] = pos[i].size() - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (ve[i].first == 1) continue;
        int x = ve[i].second;
        while (cur[x] >= 0 && pos[x][cur[x]] > i) cur[x]--;
        if (cur[x] < 0) {
            cout << -1 << '\n';
            return;
        }
        take[pos[x][cur[x]]] = true;
        cur[x]--;
    }
    int k = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (ve[i].first == 2)
            k--;
        else if (take[i])
            k++;
        ans = max(ans, k);
    }
    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
        if (ve[i].first == 2) continue;
        cout << take[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}