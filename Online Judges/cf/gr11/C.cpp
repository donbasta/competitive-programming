#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e5;

int r, n;
int t[N + 10], x[N + 10], y[N + 10], dp[N + 10];
bool vis[N + 10];

bool bisa(int a, int b) {
  return abs(t[a] - t[b]) >= abs(x[a] - x[b]) + abs(y[a] - y[b]);
}

bool comp(int a, int b) {
  return x[a] + y[a] < x[b] + y[b];
}

void solve() {
  cin >> r >> n;
  for(int i = 1; i <= n; i++) {
    cin >> t[i] >> x[i] >> y[i];
  }
  t[0] = 0, x[0] = y[0] = 1;
  vis[0] = 1;
  vector<int> ve(n + 1);
  for(int i = 0; i <= n; i++) ve[i] = i;
  sort(ve.begin(), ve.end(), comp);
  for(int i = 1; i <= n; i++) {
    for(int j = i - 1; j >= 0; j--) {
      if(bisa(ve[i], ve[j]) && vis[ve[j]]) {
        vis[ve[i]] = 1;
        // cerr << j << ' ' << i << '\n';
        dp[ve[i]] = max(dp[ve[i]], dp[ve[j]] + 1);
        break;
      }
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    // cerr << dp[i] << ' ';
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  // cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}