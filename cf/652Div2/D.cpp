#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 2e6;
const ll MOD = 1e9 + 7;

int dp[N + 69];

void init() {
  dp[1] = dp[2] = 0;
  dp[3] = dp[4] = 4;
  dp[5] = 12;
  dp[6] = 24;
  for(int i = 7; i <= N; i++) {
    if(i % 3 == 2)
      dp[i] = (2LL * dp[i - 2] + 1LL * dp[i - 1]) % MOD;
    else
      dp[i] = (4LL + 4LL * dp[i - 4] + 4LL * dp[i - 3] + dp[i - 2]) % MOD;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  init();

  // for(int i = 1; i <= 10; i++) {
  //   cout << i << ' ' << dp[i] << '\n';
  // }
  int tc;
  cin >> tc;
  while(tc--) {
    int n;
    cin >> n;
    int ans = dp[n];
    cout << ans << '\n';
  }

  return 0;
}
