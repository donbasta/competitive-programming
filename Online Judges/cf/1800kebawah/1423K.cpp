#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e6;

int dp[N + 5];
bool pr[N + 5];

void initPrime() {
  for (int i = 1; i <= N; i++) {
    pr[i] = 1;
  }
  for (int i = 2; i <= N; i++) {
    if (!pr[i]) continue;
    for (int j = i + i; j <= N; j += i) {
      pr[j] = 0;
    }
  }
  for (int i = 1; i <= N; i++) {
    dp[i] = dp[i - 1] + pr[i];
  }
}

void solve() {
  int n;
  cin >> n;
  int sq = (int) sqrt(n);
  int ans = dp[n] - dp[sq] + 1;
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  initPrime();

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}