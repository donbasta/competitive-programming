#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using matrix = vector<vector<int>>;

const ll MOD = 1e9 + 7;
const int N = 1e5 + 4;
const matrix id = {{1, 0}, {0, 1}};
const matrix mat[] = {{{1, 0}, {1, 1}}, {{1, 1}, {0, 1}}};

int n, q;
string S;
matrix seg[N << 2];
bool mk[N << 2];

matrix mul(const matrix& a, const matrix& b) {
  matrix c(2, vector<int>(2));
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
      for(int k = 0; k < 2; k++)
        c[i][j] = (1LL * c[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;
  return c;
}

void build(int v, int s, int e) {
  if(s == e) {
    seg[v] = mat[S[s] - 'A'];
  } else {
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
    seg[v] = mul(seg[v << 1], seg[v << 1 | 1]);
  }
}

void update(matrix& M) {
  swap(M[0][0], M[1][1]);
  swap(M[1][0], M[0][1]);
}

void push(int v) {
  if(mk[v]) {
    mk[v] = false;
    mk[v << 1] = mk[v << 1 | 1] = true;
    update(seg[v << 1]);
    update(seg[v << 1 | 1]);
  }
}

void upd(int v, int s, int e, int l, int r) {
  if(l > r || l > e || r < s)
    return;
  if(l <= s && r >= e) {
    mk[v] = true;
    update(seg[v]);
  } else {
    push(v);
    int mid = (s + e) >> 1;
    upd(v << 1, s, mid, l, r);
    upd(v << 1 | 1, mid + 1, e, l, r);
    seg[v] = mul(seg[v << 1], seg[v << 1 | 1]);
  }
}

matrix get(int v, int s, int e, int l, int r) {
  if(l > r || l > e || r < s)
    return id;
  if(l <= s && r >= e) {
    return seg[v];
  } else {
    push(v);
    int mid = (s + e) >> 1;
    matrix A = get(v << 1, s, mid, l, r);
    matrix B = get(v << 1 | 1, mid + 1, e, l, r);
    return mul(A, B);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n >> q >> S;
  build(1, 0, n - 1);
  while(q--) {
    int type;
    cin >> type;
    if(type == 1) {
      int l, r;
      cin >> l >> r;
      upd(1, 0, n - 1, l - 1, r - 1);
    } else if(type == 2) {
      int l, r, a, b, fi, se;
      cin >> l >> r >> a >> b;
      matrix magic = get(1, 0, n - 1, l - 1, r - 1);
      fi = (1LL * a * magic[0][0] + 1LL * b * magic[1][0]) % MOD;
      se = (1LL * a * magic[0][1] + 1LL * b * magic[1][1]) % MOD;
      cout << fi << ' ' << se << '\n';
    }
  }
  return 0;
}
