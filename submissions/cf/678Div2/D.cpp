#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;

vector<int> adj[N + 5];
ll dp[N + 5], ar[N + 5], sum[N + 5], lf[N + 5];

inline ll ceil(ll a, ll b) {
  return (a + b - 1) / b;
}

void dfs(int v, int p) {

  ll mx = -1;
  ll temp = 0;
  ll curSum = ar[v];
  ll curLeaves = 0;

  if ((int)adj[v].size() == 1 && v != 1) {
    sum[v] = ar[v];
    dp[v] = ar[v];
    lf[v] = 1;
    return;
  }

  for (auto& c : adj[v]) {
    if (c == p) continue;
    dfs(c, v);
    mx = max(mx, dp[c]);
    curLeaves += lf[c];
    curSum += sum[c];
  }
  for (auto& c : adj[v]) {
    if (c == p) continue;
    temp += (mx - dp[c]);
  }
  if (temp >= ar[v]) {
    dp[v] = mx;
  } else if (temp < ar[v]) {
    if (curSum <= curLeaves * mx) {
      dp[v] = mx;
    } else {
      dp[v] = mx + ceil(curSum - curLeaves * mx, curLeaves);
    }
  }

  sum[v] = curSum;
  lf[v] = curLeaves;
}

void solve() {
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    adj[p].push_back(i);
    adj[i].push_back(p); 
  }
  for (int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  dfs(1, 0);
  cout << dp[1] << '\n';
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