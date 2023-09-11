#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    if (k == 1) {
        for (int i = 1; i <= n; i++) {
            if (b[i] != i) {
                cout << "NO" << '\n';
                return;
            }
        }
        cout << "YES" << '\n';
        return;
    }
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int cur = i;
        unordered_map<int, bool> ump;
        while (!vis[cur]) {
            ump[cur] = true;
            vis[cur] = true;
            cur = b[cur];
        }
        if (ump.find(cur) == ump.end()) continue;
        int start_cyc = cur;
        int cnt = 1;
        cur = b[cur];
        while (cur != start_cyc) {
            cnt++;
            cur = b[cur];
        }
        if (cnt != k) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
    return;
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