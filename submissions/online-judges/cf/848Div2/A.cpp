#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> ve(n);
    int sum = 0;
    for (auto& e : ve) {
        cin >> e;
        sum += e;
    }
    const int INF = 2e9;
    int add = -INF;
    for (int i = 0; i < n - 1; i++) {
        add = max(add, -2 * (ve[i] + ve[i + 1]));
    }
    cout << sum + add << '\n';
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