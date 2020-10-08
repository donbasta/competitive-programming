#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct Line {
  mutable ll k, m, p;
  bool operator< (const Line& o) const { return k < o.k; }
  bool operator< (ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
  const ll inf = LLONG_MAX;
  ll div(ll a, ll b) {
    return a / b - ((a ^ b) < 0 && a % b);
  }
  bool isect(iterator x, iterator y) {
    if(y == end()) { x->p = inf; return false; }
    if(x->k == y->k) { x->p = (x->m > y->m) ? inf : -inf; }
    else { x->p = div(y->m - x->m, x->k - y->k); }
    return x->p >= y->p;
  }
  void add(ll k, ll m) {
    auto z = insert({k, m, 0}), y = z++, x = y;
    while(isect(y, z)) { z = erase(z); }
    if(x != begin() && isect(--x, y)) { isect(x, y = erase(y)); }
    while((y = x) != begin() && (--x)->p >= y->p) { isect(x, erase(y)); }    
  }
  ll query(ll x) {
    assert(!empty());
    auto l = *lower_bound(x);
    return l.k * x + l.m;
  }
};

const int N = 1e5;

int n;
ll a[N + 5], b[N + 5], dp[N + 5];
vector<int> adj[N + 5];
LineContainer CHT;

void dfs(int v, int p, LineContainer& cht) {
  for(auto c : adj[v]) {
    if(c == p) continue;
    LineContainer temp;
    dfs(c, v, temp);
    for(auto& lines : temp) {
      cht.add(lines.k, lines.m);
    }
  }
  if(!cht.empty()) { dp[v] = -cht.query(a[v]); }
  cht.add(-b[v], -dp[v]);
}

void solve() {
  cin >> n;
  for(int i = 1; i <= n; i++) { cin >> a[i]; }
  for(int i = 1; i <= n; i++) { cin >> b[i]; }
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0, CHT);
  for(int i = 1; i <= n; i++) {
    cout << dp[i] << (i == n ? '\n' : ' ');
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