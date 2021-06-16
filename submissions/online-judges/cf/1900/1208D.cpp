#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using node = pair<long long, int>;

const int N = 2e5;
const ll INF = 1e18;

node t[4 * N + 5];
ll lz[4 * N + 5];

int n;
ll ar[N + 5];
int ans[N + 5];

node merge(node a, node b) {
  if (a.first < b.first) return a;
  return b;
}

void build(int v, int s, int e) {
  if (s == e) {
    t[v] = make_pair(ar[s], s);
    return;
  }
  int mid = (s + e) >> 1;
  build(v << 1, s, mid);
  build(v << 1 | 1, mid + 1, e);
  t[v] = merge(t[v << 1], t[v << 1 | 1]);
}

void push(int v, int s, int e) {
  ll dec = lz[v];
  t[v << 1] = make_pair(t[v << 1].first - dec, t[v << 1].second);
  t[v << 1 | 1] = make_pair(t[v << 1 | 1].first - dec, t[v << 1 | 1].second);
  lz[v << 1] += dec;
  lz[v << 1 | 1] += dec;
  lz[v] = 0;
}

void upd(int v, int s, int e, int l, int r, ll dec) {
  if (l > r || l > e || r < s) return;
  if (s == l && e == r) {
    t[v] = make_pair(t[v].first - dec, t[v].second);
    lz[v] += dec;
    return;
  }
  push(v, s, e);
  int mid = (s + e) >> 1;
  if (r <= mid) {
    upd(v << 1, s, mid, l, r, dec);
  } else if (l >= mid + 1) {
    upd(v << 1 | 1, mid + 1, e, l, r, dec);
  } else {
    upd(v << 1, s, mid, l, mid, dec);
    upd(v << 1 | 1, mid + 1, e, mid + 1, r, dec);
  }
  t[v] = merge(t[v << 1], t[v << 1 | 1]);
}

node query(int v, int s, int e, int l, int r) {
  if (s == l && e == r) {
    return t[v];
  }
  push(v, s, e);
  int mid = (s + e) >> 1;
  if (r <= mid) {
    return query(v << 1, s, mid, l, r);
  } else if (l >= mid + 1) {
    return query(v << 1 | 1, mid + 1, e, l, r);
  } else {
    return merge(query(v << 1, s, mid, l, mid), query(v << 1 | 1, mid + 1, e, mid + 1, r));
  }
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    node T = query(1, 1, n, 1, n);
    int loc = T.second;
    // cerr << loc << '\n';
    ans[loc] = i;
    upd(1, 1, n, loc + 1, n, i);
    upd(1, 1, n, loc, loc, -INF);
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
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