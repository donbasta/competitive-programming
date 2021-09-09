#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 2000;

int n, h;
int ar[N + 5];
int dp[N + 5][N + 5];

inline void add(int& a, int b) { a = (a + b) % MOD; }

void solve() {
    cin >> n >> h;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (ar[i] + j == h) {
                if (j > 0) add (dp[i][j], dp[i - 1][j - 1]);
                add (dp[i][j], dp[i - 1][j]);  
            }
            if (ar[i] + j + 1 == h) {
                add (dp[i][j], (1LL * dp[i - 1][j + 1] * (j + 1)) % MOD);
                add (dp[i][j], dp[i - 1][j]); 
                add (dp[i][j], (1LL * dp[i - 1][j] * j) % MOD);
            }   
        }
    }
    int ans = dp[n][0] % MOD;
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