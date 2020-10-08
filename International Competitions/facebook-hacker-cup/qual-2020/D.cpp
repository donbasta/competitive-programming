#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

vector<ll> t;
int n, m;

void upd(int v, int s, int e, int pos, ll val) {
  if(s == e) {
    t[v] = val;
    return;
  }
  int mid = (s + e) >> 1;
  if(pos <= mid) {
    upd(v << 1, s, mid, pos, val);
  } else {
    upd(v << 1 | 1, mid + 1, e, pos, val);
  }
  t[v] = min(t[v << 1], t[v << 1 | 1]);
}

ll get(int v, int s, int e, int l, int r) {
  if(l > r || l > e || r < s) return INF;
  if(l <= s && r >= e) return t[v];
  int mid = (s + e) >> 1;
  return min(get(v << 1, s, mid, l, min(r, mid)), get(v << 1 | 1, mid + 1, e, max(l, mid + 1), r));
}

void solve() {
  cin >> n >> m;
  t.assign(4 * n + 10, 0);
  vector<ll> cost(n + 1);
  ll _; cin >> _;
  for(int i = 1; i < n; i++) {
    ll C;
    cin >> C;
    cost[i] = get(1, 0, n - 1, max(0, i - m), i - 1);
    if(C == 0) {
      upd(1, 0, n - 1, i, INF);
    } else {
      upd(1, 0, n - 1, i, cost[i] + C);
    }
  }
  cout << ((cost[n - 1] < INF) ? cost[n - 1] : -1) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  
  return 0;
}