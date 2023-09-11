#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int x, y;
    cin >> x >> y;
    vector<int> cnt(2);
    for (int i = 0; i < k; i++) {
        int xi, yi;
        cin >> xi >> yi;
        cnt[(xi + yi) & 1]++;
    }
    bool can = (cnt[(x + y) & 1] == 0);
    cout << (can ? "YES" : "NO") << '\n';
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