#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n + 1), lmao(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        lmao[i] = ar[i] - i;
    }
    vector<int> dp(n + 1);
    set<pair<int, int>, greater<pair<int, int>>> se;
    dp[1] = (ar[1] == 1);
    if (n == 1) {
        cout << (1 - dp[1]) << '\n';
        return;
    }
    vector<int> haha(n + 1, -1);
    haha[0] = (lmao[1] == 0) + (lmao[2] == 0);
    haha[1] = dp[1] + (lmao[2] == -1);
    se.insert(make_pair(haha[0], 0));
    se.insert(make_pair(haha[1], 1));
    for (int i = 2; i <= n; i++) {
        auto x = *se.begin();
        dp[i] = haha[i] = x.first;
        se.insert(make_pair(haha[i], i));
        if (i < n) {
            int tmp = -lmao[i + 1];
            if (tmp >= 0 && tmp <= i && se.find(make_pair(haha[tmp], tmp)) != se.end()) {
                se.erase(se.find(make_pair(haha[tmp], tmp)));
                haha[tmp]++;
                se.insert(make_pair(haha[tmp], tmp));
            }
        }
    }
    cout << (n - dp[n]) << '\n';
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