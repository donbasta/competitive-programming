#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> ve(n);
    int ans = 0;
    int one = 0;
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
        one += (ve[i] == 1);
        ans += (ve[i] != 1);
    }
    ans += ((one + 1) / 2);
    cout << ans << '\n';
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