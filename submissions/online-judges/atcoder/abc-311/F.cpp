#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i - 1][j] == '#') s[i][j] = '#';
            if (j > 0 && s[i - 1][j - 1] == '#') s[i][j] = '#';
        }
    }
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