#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e6;
const ll MOD = 1e9 + 7;

int dp[N + 69];

void fill() {
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  dp[4] = 8;
  dp[5] = 16;
  dp[6] = 32;
  for(int i = 7; i <= N; i++) {
    dp[i] = (1LL * dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4] + dp[i - 5] + dp[i - 6] ) % MOD;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  fill();

  int n;
  cin >> n;
  cout << dp[n];

  return 0;
}
