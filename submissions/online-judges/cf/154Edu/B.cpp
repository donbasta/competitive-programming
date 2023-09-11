#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.length();
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == '0' && a[i + 1] == '1' && b[i] == '0' && b[i + 1] == '1') {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
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