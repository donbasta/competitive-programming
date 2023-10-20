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
    int st = 0;
    int ans = 1;
    for (int i = 2; i < n; i += 2) {
        int sel = ve[i] - ve[i - 2];
        if (sel == 2 || sel == 0 || sel == -2) {
            continue;
        } else {
            int tmp = (i - st);
            if (st > 0) tmp++;
            ans = max(ans, tmp);
            st = i;
        }
    }
    int tmp = (n - st);
    if (st > 0) tmp++;
    ans = max(ans, tmp);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}