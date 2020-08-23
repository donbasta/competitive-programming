#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e5;

ld t[4 * N + 5], lza[4 * N + 5], lzf[4 * N + 5];
bool lz[4 * N + 5];
int ar[N + 5];

void build(int v, int s, int e) {
  if(s == e) {t[v] = (ld)ar[s]; return;}
  int mid = (s + e) >> 1;
  build(v << 1, s, mid);
  build(v << 1 | 1, mid + 1, e);
  t[v] = t[v << 1] + t[v << 1 | 1];
}

void push(int v, int s, int e) {
  if(!lz[v]) return;
  int mid = (s + e) >> 1;
  t[v << 1] = lzf[v] * t[v << 1] + lza[v] * (mid - s + 1);
  t[v << 1 | 1] = lzf[v] * t[v << 1 | 1] + lza[v] * (e - mid);
  lzf[v << 1] = lzf[v << 1] * lzf[v];
  lza[v << 1] = lza[v << 1] * lzf[v] + lza[v];
  lzf[v << 1 | 1] = lzf[v << 1 | 1] * lzf[v];
  lza[v << 1 | 1] = lza[v << 1 | 1] * lzf[v] + lza[v];
  lz[v << 1] = lz[v << 1 | 1] = 1;
  lzf[v] = 1;
  lza[v] = 0;
  lz[v] = 0;
}

void upd(int v, int s, int e, int l, int r, ld f, ld add) {
  if(r < s || l > e || l > r) return;
  if(l == s && r == e) {
    t[v] = f * t[v] + add * (e - s + 1);
    lzf[v] = lzf[v] * f;
    lza[v] = lza[v] * f + add;
    lz[v] = 1;
    return;
  }
  int mid = (s + e) >> 1;
  push(v, s, e);
  upd(v << 1, s, mid, l, min(mid, r), f, add);
  upd(v << 1 | 1, mid + 1, e, max(mid + 1, l), r, f, add);
  t[v] = t[v << 1] + t[v << 1 | 1];
}

ld sum(int v, int s, int e, int l, int r) {
  if(r < s || l > e || l > r) return 0;
  if(l == s && r == e) return t[v];
  int mid = (s + e) >> 1;
  push(v, s, e);
  return sum(v << 1, s, mid, l, min(r, mid)) + sum(v << 1 | 1, mid + 1, e, max(l, mid + 1), r);
}

int n, q;

void solve() {
  cout << fixed << setprecision(10);
  cin >> n >> q;
  fill(lzf, lzf + 4 * n + 5, 1.);
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  build(1, 1, n);
  int cnt = 0;
  while(q--) {
    int tp;
    cin >> tp;
    if(tp == 1) {
      int l1, l2, r1, r2;
      cin >> l1 >> r1 >> l2 >> r2;
      ld sum1 = sum(1, 1, n, l1, r1);
      ld sum2 = sum(1, 1, n, l2, r2);
      ld cnt1 = (ld)(r1 - l1 + 1);
      ld cnt2 = (ld)(r2 - l2 + 1);
      ld f1 = (ld)(cnt1 - 1) / (ld)(cnt1);
      ld f2 = (ld)(cnt2 - 1) / (ld)(cnt2);
      ld add1 = sum2 / (cnt1 * cnt2);
      ld add2 = sum1 / (cnt1 * cnt2);
      upd(1, 1, n, l1, r1, f1, add1);
      upd(1, 1, n, l2, r2, f2, add2);
    } else if(tp == 2) {
      int l, r;
      cin >> l >> r;
      ld ans = sum(1, 1, n, l, r);
      cout << ans << '\n';
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