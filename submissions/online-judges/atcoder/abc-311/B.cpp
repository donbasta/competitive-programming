#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, d;
    cin >> n >> d;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int tmp = 0;
    int ans = 0;
    for (int i = 0; i < d; i++) {
        int cnt_free = 0;
        for (int j = 0; j < n; j++) {
            cnt_free += s[j][i] == 'o';
        }
        if (cnt_free == n) {
            tmp++;
        } else {
            tmp = 0;
        }
        ans = max(ans, tmp);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    // cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}