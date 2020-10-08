#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e5;

int ar[N + 5];
int t[4 * N + 5];
int n, q;

int fastexpo(int a, int b) {
  int ret = 1;
  while(b) {
    if(b & 1) { ret = (1LL * ret * a) % MOD; }
    a = (1LL * a * a) % MOD;
    b >>= 1;
  }
  return ret;
}

inline int lcm(int a, int b) {
  int prod = (1LL * a * b) % MOD;
  int fpb = __gcd(a, b);
  int inv_fpb = fastexpo(fpb, MOD - 2);
  int ret = (1LL * prod * inv_fpb) % MOD;
  return ret;
}

void build(int v, int s, int e) {
  if(s == e) {
    t[v] = ar[s];
    return;
  }
  int mid = (s + e) >> 1;
  build(v << 1, s, mid);
  build(v << 1 | 1, mid + 1, e);
  t[v] = lcm(t[v << 1], t[v << 1 | 1]);
}

int get(int v, int s, int e, int l, int r) {
  if(l == s && r == e) {
    return t[v];
  }
  int mid = (s + e) >> 1;
  if(r <= mid) {
    return get(v << 1, s, mid, l, r);
  } else if(l >= mid + 1) {
    return get(v << 1 | 1, mid + 1, e, l, r);
  } else {
    int a = get(v << 1, s, mid, l, mid);
    int b = get(v << 1 | 1, mid + 1, e, mid + 1, r);
    return lcm(a, b);
  }
}

void solve() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  build(1, 1, n);
  cin >> q;
  ll last = 0;
  while(q--) {
    int x, y, l, r;
    cin >> x >> y;
    l = (last + x) % n + 1;
    r = (last + y) % n + 1;
    if(l > r) swap(l, r);
    last = get(1, 1, n, l, r);
    cout << last << '\n';
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