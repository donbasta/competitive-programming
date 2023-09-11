#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int min_n = min(a[n - 1], b[n - 1]);
    int max_n = max(a[n - 1], b[n - 1]);
    for (int i = 0; i < n - 1; i++) {
        int min_i = min(a[i], b[i]);
        int max_i = max(a[i], b[i]);
        if (!((max_i <= max_n) && (min_i <= min_n))) {
            cout << "No" << '\n';
            return;
        }
    }
    cout << "Yes" << '\n';
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