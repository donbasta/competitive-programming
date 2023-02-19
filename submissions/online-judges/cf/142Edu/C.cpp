#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), pos(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        pos[p[i] - 1] = i;
    }
    vector<pair<int, int>> lol;
    int le = 0, ri = 0;
    for (int i = 1; i < n; i++) {
        if (pos[i] > pos[i - 1]) {
            ri = i;
        } else {
            lol.emplace_back(le, ri);
            le = ri = i;
        }
    }
    lol.emplace_back(le, ri);
    int ans = INF;
    for (auto e : lol) {
        int hehe;
        int le = e.first, ri = e.second;
        if (ri < (n / 2) || le >= (n / 2)) {
            hehe = n / 2;
        } else {
            hehe = max(le, n - 1 - ri);
        }
        ans = min(ans, hehe);
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