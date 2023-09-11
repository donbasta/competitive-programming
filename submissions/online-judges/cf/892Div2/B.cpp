#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> m(n);
    vector<vector<int>> ar(n);
    int mn = INF;
    for (int i = 0; i < n; i++) {
        cin >> m[i];
        for (int j = 0; j < m[i]; j++) {
            int x;
            cin >> x;
            ar[i].push_back(x);
        }
        sort(ar[i].begin(), ar[i].end());
        mn = min(mn, ar[i][0]);
    }
    vector<int> tmp(n);
    iota(tmp.begin(), tmp.end(), 0);
    sort(tmp.begin(), tmp.end(), [&](int x, int y) -> bool {
        return ar[x][1] < ar[y][1];
    });
    ll tot = mn;
    for (int i = 1; i < n; i++) {
        tot += ar[tmp[i]][1];
    }
    cout << tot << '\n';
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