#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    if (n <= 2) {
        for (int i = 1; i <= n; i++) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    vector<int> ve(n);
    int mid = n / 2;
    ve[0] = 2;
    ve[mid] = 1;
    ve[n - 1] = 3;
    int cnt = 4;
    for (int i = 1; i < mid; i++) ve[i] = cnt++;
    for (int i = mid + 1; i < n - 1; i++) ve[i] = cnt++;
    for (auto e : ve) {
        cout << e << ' ';
    }
    cout << '\n';
    return;
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