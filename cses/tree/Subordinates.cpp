#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;

int cnt[N + 5];
vector<int> adj[N + 5];

void dfs(int v, int p) {
  cnt[v] = 1;
  for(auto c : adj[v]) {
    if(c == p) continue;
    dfs(c, v);
    cnt[v] += cnt[c];
  }
}

void solve() {
  int n;
  cin >> n;
  for(int i = 2; i <= n; i++) {
    int a;
    cin >> a;
    adj[a].push_back(i);
    adj[i].push_back(a);
  }
  dfs(1, 0);
  for(int i = 1; i <= n; i++) {
    cout << cnt[i] - 1 << ' ';
  }
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