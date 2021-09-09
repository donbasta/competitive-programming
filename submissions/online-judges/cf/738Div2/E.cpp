#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 50;
const int MX = 1e5;
const int MOD = 998244353;

int n, m;
int L[N + 5], R[N + 5];
int up[N + 5], low[N + 5];
int f[MX + 5];

inline void add(int& a, int b) { a = (a + b) % MOD; }
inline int sub(int a, int b) { 
    a = (a - b) % MOD; 
    if (a < 0) a += MOD;
    return a;
}

int calc(int k) {
    vector<vector<int>> dp(n, vector<int>(m / k + 5));
    vector<int> pre(m / k + 5);
    int bat = m / k;
    for (int i = 0; i < n; i++) {
        low[i] = ((L[i] + k - 1) / k);
        bat -= (low[i]);
        up[i] = ((R[i]) / k);
    }
    if (bat < 0) return 0;
    for (int i = 0; i <= up[0] - low[0]; i++) {
        dp[0][i] = 1;
    }
    pre[0] = 1;
    for (int i = 1; i <= bat; i++) {
        pre[i] = (pre[i - 1] + dp[0][i]) % MOD;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= bat; j++) {
            int lul;
            if (j > (up[i] - low[i])) lul = pre[j - (up[i] - low[i]) - 1];
            else lul = 0;
            dp[i][j] = (dp[i][j] + sub(pre[j], lul)) % MOD;
        }
        pre[0] = dp[i][0];
        for (int j = 1; j <= bat; j++) {
            pre[j] = (pre[j - 1] + dp[i][j]) % MOD;
        }
    }
    int ret = 0;
    for (int i = 0; i <= bat; i++) {
        ret = (ret + dp[n - 1][i]) % MOD;
    }
    return ret;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> L[i] >> R[i];
    }
    for (int i = 1; i <= m / n; i++) {
        f[i] = calc(i);
    }
    for (int i = m; i >= 1; i--) {
        for (int j = i + i; j <= m; j += i) {
            f[i] = (f[i] - f[j] + MOD) % MOD;
        }
    }
    int ans = f[1] % MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}