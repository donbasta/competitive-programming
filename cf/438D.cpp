#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e5 + 69;

int ar[4 * N];
int m, n;

struct node {
  ll sum;
  int mx, pos;
  node() : sum(0), mx(-1), pos(0) {}
  node(ll _sum, int _mx, int _pos) : sum(_sum), mx(_mx), pos(_pos) {}
  void merge(const node& a, const node& b) {
    sum = a.sum + b.sum;
    if(a.mx > b.mx) {
      mx = a.mx;
      pos = a.pos;
    } else {
      mx = b.mx;
      pos = b.pos;
    }
  }
} seg[4 * N];

void build(int v, int tl, int tr) {
  if(tl == tr) {
    seg[v] = node(ar[tl], ar[tl], tl);
  } else {
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm);
    build((v << 1) | 1, tm + 1, tr);
    seg[v].merge(seg[v << 1], seg[(v << 1) | 1]);
    return;
  }
}

void upd(int v, int tl, int tr, int pos, int val) {
  if(tl == tr) {
    assert(tl == pos);
    seg[v] = node(val, val, tl);
  } else {
    int tm = (tl + tr) >> 1;
    if(pos <= tm)
      upd(v << 1, tl, tm, pos, val);
    else
      upd((v << 1) | 1, tm + 1, tr, pos, val);
    seg[v].merge(seg[v << 1], seg[(v << 1) | 1]);
  }
}

node que(int v, int tl, int tr, int l, int r) {
  if(l > tr || r < tl)
    return node();
  if(l <= tl && r >= tr)
    return seg[v];
  int tm = (tl + tr) >> 1;
  node a = que(v << 1, tl, tm, l, min(r, tm));
  node b = que((v << 1) | 1, tm + 1, tr, max(l, tm + 1), r);
  node t = node();
  t.merge(a, b);
  return t;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  build(1, 1, n);
  while(m--) {
    int type;
    cin >> type;
    if(type == 1) {
      int l, r;
      cin >> l >> r;
      cout << que(1, 1, n, l, r).sum << '\n';
    } else if(type == 2) {
      int l, r, x;
      cin >> l >> r >> x;
      while(true) {
        node lol = que(1, 1, n, l, r);
        if(lol.mx < x)
          break;
        ar[lol.pos] %= x;
        upd(1, 1, n, lol.pos, ar[lol.pos]);
      }
    } else if(type == 3) {
      int k, x;
      cin >> k >> x;
      ar[k] = x;
      upd(1, 1, n, k, x);
    }
  }
  return 0;
}
