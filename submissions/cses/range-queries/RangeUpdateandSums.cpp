#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;

int n, q;
int ar[N + 5];
ll ad[(N << 2) + 5], t[(N << 2) + 5], se[(N << 2) + 5];

void build(int v, int s, int e) {
  if(s == e) {t[v] = ar[s]; return;}
  int mid = (s + e) >> 1;
  build(v << 1, s, mid);
  build(v << 1 | 1, mid + 1, e);
  t[v] = t[v << 1] + t[v << 1 | 1];
}

void push(int v, int s, int e) {
  int mid = (s + e) >> 1;
  if(se[v]) {
    se[v << 1] = se[v << 1 | 1] = se[v];
    t[v << 1] = 1LL * (mid - s + 1) * se[v << 1];
    t[v << 1 | 1] = 1LL * (e - mid) * se[v << 1 | 1];
    se[v] = 0;
  }
  if(ad[v]) {
    ad[v << 1] += ad[v];
    ad[v << 1] += ad[v];
    t[v << 1] += 1LL * (mid - s + 1) * ad[v << 1];
    t[v << 1 | 1] += 1LL * (e - mid) * ad[v << 1 | 1];
    ad[v] = 0;
  }
}

void upd(int v, int s, int e, int l, int r, int val, int type) {
  if(l > e || r < v) return;
  if(l == s && r == e) {
    if(type == 2) {
      t[v] = 1LL * (r - l + 1) * val;
      se[v] = val;
      ad[v] = 0;
    } else {
      t[v] += 1LL * (r - l + 1) * val;
      ad[v] += val;
    }
  }
  int mid = (s + e) >> 1;
  push(v, s, e);
  upd(v << 1, s, mid, l, min(mid, r), val, type);
  upd(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, val, type);
  t[v] = t[v << 1] + t[v << 1 | 1];
}

ll get(int v, int s, int e, int l, int r) {
  if(l > e || r < v) return 0;
  if(l == s && r == e) return t[v];
  int mid = (s + e) >> 1;
  push(v, s, e);
  return get(v << 1, s, mid, l, min(mid, r)) + get(v << 1 | 1, mid + 1, e, max(mid + 1, l), r);
}

void solve() {
  cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  build(1, 1, n);
  while(q--) {
    int type; cin >> type;
    if(type == 3) {
      int a, b; cin >> a >> b;
      cout << get(1, 1, n, a, b) << '\n';
    } else {
      int a, b, x; cin >> a >> b >> x;
      upd(1, 1, n, a, b, x, type);
    }
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