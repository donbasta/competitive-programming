#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;

int dep[N + 5];
vector<int> adj[N + 5];
pair<int, int> ans[N + 5];

void dfs(int v, int p) {
  for(auto c : adj[v]) {
    if(c == p) continue;
    dep[c] = dep[v] + 1;
    dfs(c, v);
  }
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
  int mx = -1, lol = 0;
  for(int i = 1; i <= n; i++) {
    if(dep[i] > mx) {
      lol = i; mx = dep[i];
    }
  }
  dep[lol] = 0;
  dfs(lol, 0);
  mx = -1;
  for(int i = 1; i <= n; i++) {
    ans[i].first = dep[i];
    if(dep[i] > mx) {
      lol = i; mx = dep[i];
    }
  }
  dep[lol] = 0;
  dfs(lol, 0);
  for(int i = 1; i <= n; i++) {
    ans[i].second = dep[i];
  }
  for(int i = 1; i <= n; i++) {
    cout << max(ans[i].first, ans[i].second) << ' ';
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