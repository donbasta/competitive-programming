#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ar(n), br(n + 1);
    for (int i = 0; i < n; i++) cin >> ar[i];
    for (int i = 0; i < n; i++) br[i + 1] = br[i] ^ ar[i];
    vector<int> dp(n + 1);
    map<int, int> mp;
    mp[0] = 0, dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        if (mp.count(br[i])) {
            dp[i] = max(dp[i], dp[mp[br[i]]] + 1);
        }
        mp[br[i]] = i;
    }
    cout << n - dp[n] << '\n';
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