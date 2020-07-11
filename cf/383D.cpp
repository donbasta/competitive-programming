#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1001;
const int M = 1e4;
const ll MOD = 1e9 + 7;

ll dp_[N][2 * M + 5];
int n;
int ar[N];
ll ans;

ll& dp(int pos, int num) {
  return dp_[pos][num + M];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  for(int i = 1; i <= n; i++) {
    dp(i, ar[i])++;
    dp(i, -ar[i])++;
  }
  for(int i = 2; i <= n; i++) {
    for(int j = -M; j <= M; j++) {
      if(abs(j + ar[i]) <= M){
        dp(i, j + ar[i]) += dp(i - 1, j);
        dp(i, j + ar[i]) %= MOD;
      }
      if(abs(j - ar[i]) <= M){
        dp(i, j - ar[i]) += dp(i - 1, j);
        dp(i, j - ar[i]) %= MOD;
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    // for(int j = -4; j <= 4; j++) {
    //   cout << i << ' ' << j << ' ' << dp(i, j) << '\n';
    // }
    ans = (ans + dp(i, 0)) % MOD;
  }
  cout << ans << '\n';

  return 0;
}
