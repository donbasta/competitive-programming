#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e5 + 69;

int n;
vector<int> adj[N];
int dep[N];

void dfs(int v = 1, int par = 0, int d = 1) {
  dep[v] = d;
  for(auto i : adj[v]) {
    if(i == par)
      continue;
    dfs(i, v, d + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs();
  ld ans = 0;
  for(int i = 1; i <= n; i++) {
    ans = (ans + ((ld) 1 / (ld) (dep[i])));
  }
  cout << fixed << setprecision(15) << ans << '\n';
  return 0;
}
