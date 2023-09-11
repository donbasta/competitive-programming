#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[0] == a.back()) {
        cout << -1 << '\n';
        return;
    }
    int idx = 0;
    while (a[idx] < a.back()) idx++;
    cout << idx << ' ' << n - idx << '\n';
    for (int i = 0; i < idx; i++) cout << a[i] << ' ';
    cout << '\n';
    for (int i = idx; i < n; i++) cout << a[i] << ' ';
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