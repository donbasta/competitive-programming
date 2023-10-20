#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> p(n);
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        p[i] = make_pair(make_pair(s, e), i);
    }
    int S0 = p[0].first.first;
    int E0 = p[0].first.second;
    int E = -1;
    sort(p.begin(), p.end(), greater<>());
    for (int i = 0; i < n; i++) {
        if (p[i].first.first < S0) break;
        E = max(E, p[i].first.second);
    }
    if (E0 < E) {
        cout << -1 << '\n';
        return;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (p[i].first.first < S0) break;
        if (p[i].first.second == E) cnt++;
    }
    if (cnt >= 2) {
        cout << -1 << '\n';
        return;
    }
    cout << S0 << '\n';
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