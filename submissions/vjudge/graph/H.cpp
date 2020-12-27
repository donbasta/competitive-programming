#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 500;

int dp[N + 5][N + 5];

inline void solve() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      int we;
      cin >> we;
      dp[i][j] = we;
    }
  }
  vector<int> node;
  vector<ll> ans;
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    node.push_back(x);
  }
  reverse(node.begin(), node.end());
  int cur = 0;
  for(auto i : node) {
    ll sum = 0;
    for(auto j : node) {
      for(auto k : node) {
        dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
      }
    }
    for(int j = 0; j <= cur; j++) {
      for(int k = 0; k <= cur; k++) {
        sum += 1LL * dp[node[j]][node[k]];
      }
    }
    ans.push_back(sum);
    cur++;
  }
  reverse(ans.begin(), ans.end());
  for(auto i : ans) {
    cout << i << ' ';
  }
  cout << '\n';
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