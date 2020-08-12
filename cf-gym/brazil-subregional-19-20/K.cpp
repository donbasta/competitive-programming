#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;

typedef vector<vector<ll>> matrix;
matrix A, B;
vector<ll> a, b;
int n;

matrix mul(matrix a, matrix b, int sz){
  matrix d(sz, vector<ll>(sz));
  for(int i = 0; i < sz; i++) {
    for(int j = 0; j < sz; j++) {
      for(int k = 0; k < sz; k++) {
        d[i][j] = (d[i][j] + a[i][k] * b[k][j]) % MOD;
      }
    }
  }
  return d;
}

matrix id(int sz) {
  matrix ret;
  for(int i = 0; i < sz; i++) {
    vector<ll> temp;
    for(int j = 0; j < sz; j++) {
      temp.push_back((i == j) ? 1 : 0);
    }
    ret.push_back(temp);
  }
  return ret;
}
 
matrix fast_expo(matrix a, ll b){
  int sz = (int) a.size();
  matrix ret = id(sz);
  while(b) {
    if(b & 1) {ret = mul(ret, a, sz);}
    a = mul(a, a, sz);
    b >>= 1;
  }
  return ret;
}

void init() {
  a = {1, 2, 12, 40};
  b = {-1, -1, 16, 80, 320, 1216};
  A = {{4, 0, -8}, {1, 0, 0}, {0, 1, 0}};
  B = {{6, -8, -8, 16}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}};
}

void solve() {
  cin >> n;
  init();
  if(n == 1) {cout << 2 << '\n'; return;}
  if(n <= 5) {cout << b[n] + 8 * a[n - 2] << '\n'; return;}
  A = fast_expo(A, n - 4);
  B = fast_expo(B, n - 5);
  ll aa = 0, bb = 0;
  for(int i = 0; i < 3; i++) {
    aa += A[0][i] * a[2 - i];
    aa %= MOD;
  }
  for(int i = 0; i < 4; i++) {
    bb += B[0][i] * b[5 - i];
    bb %= MOD;
  }
  ll ans = bb + 8 * aa;
  ans %= MOD;
  if(ans < 0) ans += MOD;
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