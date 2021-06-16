#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int M = 2e4;

bool comp[M + 10];

int n, K;
vector<bool> done, vis;
vector<int> deg, needed, par, ar;
vector<vector<int>> adj, ans;

void initPrime() {
  for(int i = 2; i <= M; i++) {
    if(comp[i]) continue;
    for(int j = i + i; j <= M; j += i) {
      comp[j] = true;
    }
  }
}

void dfs(int v, int p) {
  cerr << v << ' ' << p << '\n';
  if(done[v]) return;
  vis[v] = true;
  for(auto i : adj[v]) {
    if(i == p || done[i]) continue;
    if(vis[i]) {
      int cur = v;
      int now = K++;
      ans.push_back(vector<int>());
      ans[now].push_back(i);
      done[i] = true;
      while(cur != i) {
        ans[now].push_back(cur);
        done[cur] = true;
        cerr << i << ' ' << cur << ' ' << par[cur] << '\n';
        cur = par[cur];
      }
      return;
    }
    par[i] = v;
    dfs(i, v);
    if(done[v]) return;
  }
}

void solve() {
  int n;
  cin >> n;
  deg.resize(n), ar.resize(n), par.resize(n);
  adj.resize(n), needed.resize(n);
  done.resize(n), vis.resize(n);

  initPrime();

  vector<int> cnt(2);
  for(int i = 0; i < n; i++) {
    cin >> ar[i];
    cnt[ar[i] & 1]++;
  }
  if(cnt[0] != cnt[1]) {
    cout << "Impossible" << '\n';
    return;
  }
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      int temp = ar[i] + ar[j];
      if(!comp[temp]) {
        deg[i]++; deg[j]++;
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }
  int mn = *min_element(deg.begin(), deg.end());
  if(mn <= 1) {
    cout << "Impossible" << '\n';
    return;
  }
  for(int i = 0; i < n; i++) {
    if(deg[i] == 2) {
      for(auto j : adj[i])
        needed[j]++;
    }
  }
  int mx = *max_element(needed.begin(), needed.end());
  if(mx > 2) {
    cout << "Impossible" << '\n';
    return;
  }
  for(int i = 0; i < n; i++) {
    if(!done[i]) dfs(i, -1);
  }
  cout << K << '\n';
  for(int i = 0; i < K; i++) {
    cout << (int) ans[i].size() << ' ';
    for(auto& e : ans[i]) {
      cout << e + 1 << ' ';
    }
    cout << '\n';
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