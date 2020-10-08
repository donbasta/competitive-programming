#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;
using ll = long long;
using ld = long double;

const int INF = 1e9;

int n;
vector<int> dp0, dp1;
vector<vector<int>> adj;

void dfs(int v, int p) {
  int ch = 0;
  pair<int, int> mx = mp(-1, -1);
  int mx0 = -1;
  dp0[v] = -INF;
  dp1[v] = 1;
  for(auto& c : adj[v]) {
    if(c == p) continue;
    ch++;
    dfs(c, v);
    if(dp1[c] > mx.fi) {
      mx.se = mx.fi, mx.fi = dp1[c];
    } else if(dp1[c] > mx.se) {
      mx.se = dp1[c];
    }
    mx0 = max(mx0, dp0[c]);
  }
  if(ch == 0) {
    dp0[v] = -INF;
    dp1[v] = 1; 
    return;
  } else if(ch == 1) {
    dp0[v] = -INF;
    dp1[v] = 1 + max(mx.fi, mx0);
    return;
  }
  dp1[v] = max(dp1[v], ch + 1);
  if(mx.fi >= 0) dp1[v] = max(dp1[v], mx.fi + ch);
  if(mx0 >= 0) dp1[v] = max(dp1[v], 1 + mx0);
  if(mx.se <= 1) dp0[v] = -INF;
  else dp0[v] = mx.fi + mx.se + ch - 1;
  
}

void init() {
  adj.assign(n + 1, vector<int>());
  dp0.assign(n + 1, 0);
  dp1.assign(n + 1, 0);
}

void solve() {
  cin >> n;
  init();
  for(int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1, 0);
  int ans = -1;
  for(int i = 1; i <= n; i++) {
    ans = max(ans, dp0[i]);
    ans = max(ans, dp1[i]);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}