#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> ve(2);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ve[x & 1].push_back(i + 1);
    }
    if (ve[1].size() == 0) {
        cout << "NO" << '\n';
        return;
    }
    if (ve[1].size() == 1) {
        cout << "YES" << '\n';
        cout << ve[1][0] << ' ' << ve[0][0] << ' ' << ve[0][1] << '\n';
        return;
    }
    if (ve[1].size() == 2) {
        if (ve[0].size() == 1) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
            cout << ve[1][0] << ' ' << ve[0][0] << ' ' << ve[0][1] << '\n';
        }
        return;
    }
    if (ve[1].size() >= 3) {
        cout << "YES" << '\n';
        cout << ve[1][0] << ' ' << ve[1][1] << ' ' << ve[1][2] << '\n';
    }
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