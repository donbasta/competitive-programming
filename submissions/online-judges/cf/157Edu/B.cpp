#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ve(n * 2);
    for (int i = 0; i < 2 * n; i++) {
        cin >> ve[i];
    }
    sort(ve.begin(), ve.end());
    int ans = ve[2 * n - 1] + ve[n - 1] - ve[n] - ve[0];
    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
        cout << ve[i + n] << ' ' << ve[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}