#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n % 2 == 0) {
        cout << 2 << '\n';
        cout << 1 << ' ' << n << '\n';
        cout << 1 << ' ' << n << '\n';
    } else {
        cout << 4 << '\n';
        cout << 1 << ' ' << n - 1 << '\n';
        cout << 1 << ' ' << n - 1 << '\n';
        cout << 2 << ' ' << n << '\n';
        cout << 2 << ' ' << n << '\n';
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