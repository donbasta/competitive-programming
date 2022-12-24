#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    int k = n / 5;
    int m = n % 5;
    vector<int> sisa = {0, 1, 1, 1, 1, 1};
    int ans = k + sisa[m];
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
