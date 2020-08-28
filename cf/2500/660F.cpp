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

const int N = 2e5;

int n;
ll ar[N + 5], skor[N + 5], pre[N + 5];
LineContainer cht;

void solve() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
    pre[i] = pre[i - 1] + ar[i];
    skor[i] = ar[i] * i + skor[i - 1];
  }
  cht.add(0, 0);
  ll ans = 0;
  for(ll i = 1; i <= n; i++) {
    ll mx = cht.query(pre[i]);
    ans = max(ans, skor[i] + mx);
    cht.add(-i, i * pre[i] - skor[i]);
  }
  cout << ans << '\n';
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