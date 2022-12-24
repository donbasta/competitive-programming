#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int n;
        cin >> n;
        vector<int> ve(n + 1);
        int mx = -1, ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
        }
        for (int i = 1; i <= n; i++) {
            bool ok = true;
            ok &= (ve[i] > mx);
            if (i < n) {
                ok &= (ve[i] > ve[i + 1]);
            }
            ans += ok;
            mx = max(mx, ve[i]);
        }
        cout << "Case #" << tc << ": ";
        cout << ans << '\n';
    }

    return 0;
}