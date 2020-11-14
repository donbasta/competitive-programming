#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int a, b;
const int N = 1e4;
const int N2 = 5e3;

vector<int> adj[N + 5];
bool vis[N + 5], col[N + 5], flip[N + 5];
vector<pair<int, int>> sz;
int kel[N + 5];
int KEL;
int mem[N + 5][N2 + 5];

void dismiss() {
  cout << -1 << '\n';
  exit(0);
}

void dfs(int v) {
  kel[v] = KEL;
  for (auto& e : adj[v]) {
    if (vis[e]) {
      if (col[e] == col[v]) {
        dismiss();
      }
    } else {
      vis[e] = 1;
      col[e] = col[v] ^ 1;
      if (col[e]) a++;
      else b++;
      dfs(e);
    }
  }
}

int dp(int id, int s) {
  if (s < 0)
    return 0;
  if (id == (int)sz.size()) {
    return s == 0;
  }
  int& ret = mem[id][s];
  if (ret != -1)
    return ret;
  ret = dp(id+1, s-sz[id].first);
  if (ret)
    return ret;
  ret = dp(id+1, s-sz[id].second);
  return ret;
}

void bt(int id, int s) {
  if (id == (int)sz.size())
    return;
  if (dp(id+1, s-sz[id].first)){
    // cerr << "noflip " << id+1 << ' ' << s-sz[id].first << '\n';
    bt(id+1, s-sz[id].first);
  } else {
    assert(dp(id+1, s-sz[id].second));
    // cerr << "flip " << id+1 << ' ' << s-sz[id].second << '\n';
    flip[id] = 1;
    bt(id+1, s-sz[id].second);
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  if (n & 1) {
    dismiss();
  }

  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      a = b = 0;
      vis[i] = 1, col[i] = 1;
      a++;
      dfs(i);
      sz.emplace_back(a, b);
      KEL++;
    }
  }

  memset(mem, -1, sizeof mem);
  if (!dp(0, n/2)) {
    dismiss();
  }

  bt(0, n/2);

  vector<int> pos(2*n + 5);
  int ki = 1, ka = 2;
  for (int i = 1; i <= n; i++) {
    int gr = kel[i];
    if (flip[gr]) {
      if (col[i]) {
        // assert(ki <= n);
        pos[ki] = i;
        ki += 2;
      } else {
        // assert(ka <= n);
        pos[ka] = i;
        ka += 2;
      }
    } else {
      if (col[i]) {
        // assert(ka <= n);
        pos[ka] = i;
        ka += 2;
      } else {
        // assert(ki <= n);
        pos[ki] = i;
        ki += 2;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << pos[i] << ' ';
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