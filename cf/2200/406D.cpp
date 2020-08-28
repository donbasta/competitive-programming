#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct point {
  ll x, y;
  point(ll x = 0, ll y = 0) : x(x), y(y) {}
  point operator+(const point& p) const {return point(x + p.x, y + p.y);}
  point operator-(const point& p) const {return point(x - p.x, y - p.y);}
  ll operator%(const point& p) {return x * p.y - y * p.x;}
};

int ccw(point a, point b, point c) {
  ll cross = (b - a) % (c - b);
  if(cross > 0) return 1;
  else if(cross == 0) return 0;
  return -1;
}

const int N = 1e5;
const int M = 18;

int n, m, timer, lg;
vector<int> adj[N + 5];
int tin[N + 5], tout[N + 5];
int up[N + 5][M + 2];

void dfs(int v, int p) {
  tin[v] = ++timer;
  up[v][0] = p;
  for(int i = 1; i <= lg; i++) {
    up[v][i] = up[up[v][i - 1]][i - 1];
  }
  for(int c : adj[v]) {
    if(c == p) continue;
    dfs(c, v);
  }
  tout[v] = ++timer;
}

bool isAncestor(int a, int b) {
  return tin[a] <= tin[b] && tout[a] >= tout[b]; 
}

int LCA(int a, int b) {
  if(isAncestor(a, b)) return a;
  if(isAncestor(b, a)) return b;
  for(int i = lg; i >= 0; i--) {
    if(!isAncestor(up[a][i], b)) a = up[a][i];
  }
  return up[a][0];
}

void solve() {
  cin >> n;
  lg = ceil(log2(n));
  vector<point> ve;
  for(int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    ve.emplace_back(x, y);
  }
  vector<pair<point, int>> ch;
  ch.emplace_back(ve[n - 1], n - 1);
  for(int i = n - 2; i >= 0; i--) {
    int sz = (int)ch.size();
    while((sz >= 2) && ccw(ch[sz - 2].first, ch[sz - 1].first, ve[i]) < 0) {
      ch.pop_back();
      sz--;
    }
    adj[i].push_back(ch.back().second);
    adj[ch.back().second].push_back(i);
    ch.emplace_back(ve[i], i);
  }
  dfs(n - 1, n - 1);
  cin >> m;
  while(m--) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    cout << LCA(a, b) + 1 << '\n';
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