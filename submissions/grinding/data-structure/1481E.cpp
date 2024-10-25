#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ar(n + 1);
    vector<int> dp(n + 1), le(n + 1, -1), ri(n + 1, -1), cnt(n + 1), col(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        cnt[ar[i]]++;
        if (le[ar[i]] == -1) le[ar[i]] = i;
        ri[ar[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (le[i] == -1 || ri[i] == -1) continue;
        col[ri[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        if (col[i] != 0) {
            dp[i] = max(dp[i], dp[le[col[i]] - 1] + cnt[col[i]]);
        }
    }
    vector<int> mx_freq(n + 2), tmp(n + 1);
    int mx = 0;
    for (int i = n; i >= 1; i--) {
        tmp[ar[i]]++;
        mx = max(mx, tmp[ar[i]]);
        mx_freq[i] = mx;
    }

    int ans = n;
    for (int i = 0; i <= n; i++) {
        int move = (i - dp[i]) + (n - i - mx_freq[i + 1]);
        // cerr << i << ' ' << move << '\n';
        ans = min(ans, move);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}