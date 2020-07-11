#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using matrix = vector<vector<int>>;

const int N = 1e5 + 69;
const ll MOD = 1e9 + 7;
const int SIZE = 2;

matrix mul(matrix a, matrix b) {
  matrix res(SIZE, vector<int>(SIZE));
  for(int i = 0; i < SIZE; i++) {
    for(int j = 0; j < SIZE; j++) {
      for(int k = 0; k < SIZE; k++) {
        res[i][j] = (1LL * a[i][k] * b[k][j] + 1LL * res[i][j]) % MOD;
      }
    }
  }
  return res;
}

matrix fpow(matrix a, ll b) {
  if(b == 1) return a;
  if(b & 1) return mul(a, fpow(a, b - 1));
  matrix res = fpow(a, b / 2);
  return mul(res, res);
}

int f(ll x) {
  if(x == 0) return 0;
  if(x <= 2) return 1;
  matrix magic = {{1, 1}, {1, 0}};
  matrix init = {{1}, {1}};
  matrix ret = fpow(magic, x - 2);
  return (1LL * ret[0][0] + 1LL * ret[0][1]) % MOD;
}

int n, m;
int ar[N];
ll lz[N << 2];

struct info {
  int a, b;
  info(int _a = 0, int _b = 0) : a(_a), b(_b) {}
  void merge(const info& i1, const info& i2) {
    a = (1LL * i1.a + 1LL * i2.a) % MOD;
    b = (1LL * i1.b + 1LL * i2.b) % MOD;
  }
  void updVal(ll x) {
    if(x == 0) return;
    int fa, fb, fc;
    fa = f(x + 1); fb = f(x); fc = f(x - 1);
    int temp = a;
    a = (1LL * fa * temp + 1LL * fb * b) % MOD;
    b = (1LL * fb * temp + 1LL * fc * b) % MOD;
  }
} seg[N << 2];

void build(int v, int tl, int tr) {
  if(tl == tr) {
    seg[v] = info(f(ar[tl]), f(ar[tl] - 1));
    return;
  }
  int tm = (tl + tr) / 2;
  build(v << 1, tl, tm);
  build((v << 1) | 1, tm + 1, tr);
  seg[v].merge(seg[v << 1], seg[(v << 1) | 1]);
}

void push(int v) {
  lz[v << 1] += lz[v];
  seg[v << 1].updVal(lz[v]);
  lz[(v << 1) | 1] += lz[v];
  seg[(v << 1) | 1].updVal(lz[v]);
  lz[v] = 0;
}

void upd(int v, int tl, int tr, int l, int r, int add) {
  if(l > r)
    return;
  if(l == tl && r == tr){
    lz[v] += 1LL * add;
    seg[v].updVal(add);
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  upd(v << 1, tl, tm, l, min(r, tm), add);
  upd((v << 1) | 1, tm + 1, tr, max(l, tm + 1), r, add);
  seg[v].merge(seg[v << 1], seg[(v << 1) | 1]);
}

info que(int v, int tl, int tr, int l, int r) {
  if(l > r)
    return info();
  if(l <= tl && r >= tr)
    return seg[v];
  push(v);
  int tm = (tl + tr) / 2;
  info a = que(v << 1, tl, tm, l, min(r, tm));
  info b = que((v << 1) | 1, tm + 1, tr, max(l, tm + 1), r);
  info ret = info();
  ret.merge(a, b);
  return ret;
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
    int q, l, r, x;
    cin >> q;
    if(q == 1) {
      cin >> l >> r >> x;
      upd(1, 1, n, l, r, x);
    } else if(q == 2) {
      cin >> l >> r;
      cout << que(1, 1, n, l, r).a << '\n';
    }
  }
  return 0;
}
