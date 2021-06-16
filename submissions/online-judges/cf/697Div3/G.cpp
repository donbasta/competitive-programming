#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5 + 5;
const int INF = 2e9;

int n;
vector<int> divisor[N + 5];
int cnt[N + 5], dp[N + 5];

void init() {
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            divisor[j].emplace_back(i);
        }
    }
}

void solve() {
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= N; i++) {
        for (auto e : divisor[i]) {
            dp[i] = max(dp[i], dp[e]);
        }
        dp[i] += cnt[i];
    }
    int ans = INF;
    for (int i = 1; i <= N; i++) {
        ans = min(ans, n - dp[i]);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    init();

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}