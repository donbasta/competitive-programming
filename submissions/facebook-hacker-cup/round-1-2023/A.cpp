#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> ve(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }
    sort(ve.begin(), ve.end());
    int dif;
    if (n == 4 || n >= 6) {
        int a = (ve[0] + ve[1]);
        int b = (ve[n - 2] + ve[n - 1]);
        dif = b - a;
    } else if (n == 5) {
        dif = max(ve[2] + ve[4] - ve[0] - ve[1], ve[3] + ve[4] - ve[2] - ve[0]);
    }
    ld ret = (ld)(dif) / 2;
    cout << fixed << setprecision(9) << ret << '\n';
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