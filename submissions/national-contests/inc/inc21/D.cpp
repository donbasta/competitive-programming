#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> ve(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> ve[i].second;
    }
    sort(ve.begin(), ve.end());
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