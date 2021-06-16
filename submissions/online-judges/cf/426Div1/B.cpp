#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void compute(int idx, int l, int r, int optl, int optr) {
  if(l > r) return;
  int mid = (l + r) >> 1;
  pair<ll, int> best = make_pair(INF, -1);
  for(int k = optl; k <= min(mid, optr); k++) {
    best = min(best, make_pair(dp[idx - 1][k] + calc(k + 1, mid), k));
  }
  dp[idx][mid] = best.first;
  int opt = best.second;
  compute(idx, l, mid - 1, optl, opt);
  compute(idx, mid + 1, r, opt, optr);
}

void solve() {
  cin >> n >> k;
  for(int i = 1; i <= n; i++)
    cin >> ar[i];
  for(int i = 1; i <= k; i++) {
    compute(i, 1, n, 1, n);
  }
  cout << dp[k][n] << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tc = 1;
  // cin >> tc;
  while(tc--) {
    solve();
  }
  
  return 0;
}