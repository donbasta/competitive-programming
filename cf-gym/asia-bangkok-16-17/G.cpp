#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;

inline ll sub(ll a, ll b) { return (((a - b) % MOD) + MOD) % MOD; }
inline ll add(ll a, ll b) { return (((a + b) % MOD) + MOD) % MOD; }

struct Matrix {
  int sz;
  vector<vector<ll>> ve;
  Matrix(int _sz = 0) : sz(_sz) {
    ve.assign(sz, vector<ll>(sz));
  }
  Matrix(const vector<vector<ll>>& other) {
    sz = other.size();
    ve = other;
  }
  Matrix operator*(const Matrix& b){
    Matrix ret(sz);
    for(int i = 0; i < sz; i++) {
      for(int j = 0; j < sz; j++) {
        for(int k = 0; k < sz; k++) {
          ret.ve[i][j] = (ret.ve[i][j] + ve[i][k] * b.ve[k][j]) % MOD;
        }
      }
    }
    return ret;
  }
  Matrix operator^(ll a) {
    Matrix ret(sz), cur = *this;
    for(int i = 0; i < sz; i++) { ret.ve[i][i] = 1; }
    while(a) {
      if(a & 1) { ret = ret * cur; }
      cur = cur * cur;
      a >>= 1; 
    }
    return ret;
  }
};

ll l, r;
int k;

void solve() {
  Matrix fibo({{1, 1}, {1, 0}});
  cin >> l >> r >> k;
  ll tr = r / k, tl = (l - 1) / k;
  if(tl > tr) {
    cout << 0 << '\n';
    return;
  }
  fibo = fibo ^ (k + 1);
  ll fa, fb, fc;
  fa = fibo.ve[0][1], fb = fibo.ve[1][1];
  fc = sub(fa, fb);
  Matrix magic({{fc + 1, fb, -fc, -fb}, {fb, fa + 1, -fb, -fa}, {1, 0, 0, 0}, {0, 1, 0, 0}});
  ll bl, br;
  ll init[] = {fb, fa, 0, 0};
  if(tl <= 1) {
    bl = add(init[3 - 2 * tl], init[2 - 2 * tl]);
  } else {
    Matrix temp = magic ^ (tl - 1);
    bl = (temp.ve[0][0] * init[0] + temp.ve[0][1] * init[1] + temp.ve[0][2] * init[2] + temp.ve[0][3] * init[3]) % MOD;
    bl = add(bl, (temp.ve[1][0] * init[0] + temp.ve[1][1] * init[1] + temp.ve[1][2] * init[2] + temp.ve[1][3] * init[3]) % MOD);
  }
  if(tr <= 1) {
    br = add(init[3 - 2 * tr], init[2 - 2 * tr]);
  } else {
    Matrix temp = magic ^ (tr - 1);
    br = (temp.ve[0][0] * init[0] + temp.ve[0][1] * init[1] + temp.ve[0][2] * init[2] + temp.ve[0][3] * init[3]) % MOD;
    br = add(br, (temp.ve[1][0] * init[0] + temp.ve[1][1] * init[1] + temp.ve[1][2] * init[2] + temp.ve[1][3] * init[3]) % MOD);
  }
  cout << sub(br, bl) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    cout << "Case " << i << ": ";
    solve();
  }
  
  return 0;
}