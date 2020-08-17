#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;

int DP[N + 5], dp1[N + 5], dp0[N + 5];
vector<int> adj[N + 5];

void dfs(int v, int p) {
  int temp = 0, mx = -1;
  for(auto c : adj[v]) {
    if(c == p) continue;
    dfs(c, v);
    temp += DP[c];
  }
  dp0[v] = temp;
  for(auto c : adj[v]) {
    if(c == p) continue;
    mx = max(mx, temp - DP[c] + dp0[c] + 1);
  }
  dp1[v] = mx;
  DP[v] = max(dp0[v], dp1[v]);
}

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1, 0);
  cout << DP[1] << '\n';
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