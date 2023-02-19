#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    vector<bool> vis(n), isWin(n);
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        vector<int> tmp;
        tmp.push_back(i);
        vis[i] = true;
        int cur = i + ar[i];
        while ((cur >= 0) && (cur < n) && (!vis[cur])) {
            vis[cur] = true;
            tmp.push_back(cur);
            cur = cur + ar[cur];
        }
        if (cur < 0 || cur >= n) {
            for (auto e : tmp) {
                isWin[e] = true;
            }
        } else {
            for (auto e : tmp) {
                isWin[e] = isWin[cur];
            }
        }
    }
    int wins = 0;
    for (int i = 0; i < n; i++) {
        wins += isWin[i];
    }
    vector<int> hehe;
    hehe.push_back(0);
    int cur = ar[0];
    vector<bool> vis2(n);
    vis2[0] = true;
    while ((cur >= 0) && (cur < n) && (!vis2[cur])) {
        vis2[cur] = true;
        hehe.push_back(cur);
        cur = cur + ar[cur];
    }
    int winningFromStart = (cur < 0) || (cur >= n);
    ll ans = 0;
    int own = hehe.size();
    if (winningFromStart) {
        ans += 1LL * (n - own) * (2 * n + 1);
        for (int i = 0; i < own; i++) {
            ans += (wins - i - 1);
            ans += (n + 1);
        }
    } else {
        for (int i = 0; i < own; i++) {
            ans += (wins + n + 1);
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