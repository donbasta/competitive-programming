#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

pii mx(pii a, pii b) {
  if(min(a.first, a.second) > min(b.first, b.second)) return a;
  else if(min(a.first, a.second) < min(b.first, b.second)) return b;
  else {
    if(max(a.first, a.second) > max(b.first, b.second)) return a;
    else return b;
  }
}

void solve() {
  int N, K;
  cin >> N >> K;
  vector<vector<pair<int, int>>> dp(N + 1, vector<pair<int, int>>(K + 1));
  vector<pair<int, int>> ve;
  for(int i = 0; i < N; i++) {
    ll x;
    cin >> x;
    int a = 0, b = 0;
    while(x % 2 == 0) x /= 2, a++;
    while(x % 5 == 0) x /= 5, b++;
    ve.emplace_back(a, b);
    cerr << i << ' ' << a << ' ' << b << '\n';
  }
  for(int i = 0; i < N; i++) {
    dp[i][0] = ve[i];
  }
  for(int i = 0; i < N; i++) {
    for(int j = 1; j < K; j++) {
      if(i < j) continue;
      for(int k = 0; k < i; k++) {
        if(k < j - 1) continue;
        dp[i][j] = mx(dp[i][j], make_pair(dp[k][j - 1].first + ve[i].first, dp[k][j - 1].second + ve[i].second));
      }
    }
  }
  for(int i = 0; i < N; i++)
    for(int j = 0; j < K; j++)
      cerr << i << ' ' << j << ' ' << dp[i][j].first << ' ' << dp[i][j].second << '\n';
  int mx = 0;
  for(int i = 0; i < N; i++) {
    int temp = min(dp[i][K - 1].first, dp[i][K - 1].second);
    mx = max(mx, temp);
  }
  cout << mx << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  // cin >> TC;
  for(int i = 1; i <= TC; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  
  return 0;
}