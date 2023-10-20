#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int B = 0;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        B = (B | b[i]);
    }
    int mx = 0, mn = 0;
    if (n & 1) {
        for (int i = 0; i < n; i++) {
            mx ^= (a[i] | B);
            mn ^= a[i];
        }
    } else {
        for (int i = 0; i < n; i++) {
            mx ^= a[i];
            mn ^= (a[i] | B);
        }
    }
    cout << mn << ' ' << mx << '\n';
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