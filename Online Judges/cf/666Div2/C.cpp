#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;
const int N = 1e6;

inline ll MIN(ll a, ll b, ll c) { return min(a, min(b, c)); }
inline void upd(ll& a, ll b) { a = min(a, b); }

ll dp[N + 5][3];
ll DP[N + 5];
ll n, r1, r2, r3, d;
ll lul[N + 5], lol[N + 5], ar[N + 5];

void solve() {
  cin >> n;
  cin >> r1 >> r2 >> r3;
  cin >> d;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
    lol[i] = ar[i] * r1 + r3;
    lul[i] = min(r2, ar[i] * r1 + r1);
  }
  if(n == 2) {
    ll ans = INF;
    upd(ans, lol[1] + d + lol[2]);
    upd(ans, lul[1] + 2LL * d + lol[2] + r1);
    upd(ans, lul[1] + lul[2] + 3LL * d + 2LL * r1);
    cout << ans << '\n';
    return;
  }
  DP[0] = 0;
  dp[1][0] = lol[1];
  dp[1][1] = dp[1][2] = INF;
  DP[1] = MIN(dp[1][0], dp[1][1], dp[1][2]);
  dp[2][0] = lol[1] + lol[2] + d;
  dp[2][1] = lul[1] + lul[2] + 3LL * d + 2LL * r1;
  dp[2][2] = INF;
  DP[2] = MIN(dp[2][0], dp[2][1], dp[2][2]);
  for(int i = 3; i < n; i++) {
    dp[i][0] = lol[i] + d + DP[i - 1];
    dp[i][1] = (lul[i] + lul[i - 1] + 3LL * d + 2LL * r1) + d + DP[i - 2];
    dp[i][2] = (lul[i] + lul[i - 1] + lul[i - 2] + 6LL * d + 3LL * r1) + DP[i - 3] + (i > 3 ? d : 0);
    DP[i] = MIN(dp[i][0], dp[i][1], dp[i][2]);
  }
  ll ans = INF;
  upd(ans, lol[n] + d + DP[n - 1]);
  upd(ans, DP[n - 2] + 3LL * d + lul[n - 1] + lol[n] + r1);
  upd(ans, DP[n - 2] + 4LL * d + lul[n - 1] + lul[n] + 2LL * r1);
  upd(ans, DP[n - 3] + (n > 3 ? d : 0) + lul[n - 2] + lul[n - 1] + lol[n] + 4LL * d + 2LL * r1);
  upd(ans, DP[n - 3] + (n > 3 ? d : 0) + lul[n - 2] + lul[n - 1] + lul[n] + 3LL * r1 + 6LL * d);
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