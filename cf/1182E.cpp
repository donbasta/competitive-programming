#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int PR_MOD = 5;

typedef vector<vector<int>> matrix;

matrix magic;
int f[5], lg[5];
ll n;
int c;

matrix mul(matrix a, matrix b, int sz){
  matrix d(sz, vector<int>(sz));
  for(int i = 0; i < sz; i++) {
    for(int j = 0; j < sz; j++) {
      for(int k = 0; k < sz; k++) {
        d[i][j] = (1LL * d[i][j] + 1LL * a[i][k] * b[k][j]) % (MOD - 1);
      }
    }
  }
  return d;
}
 
matrix fast_expo(matrix a, ll b){
  int sz = (int) a.size();
  if(b == 1) return a;
  if(b % 2 == 1) return mul(a, fast_expo(a, b - 1), sz);
  matrix c = fast_expo(a, b/2);
  return mul(c, c, sz);
}

int powmod(int a, int b, int p) {
  int ret = 1;
  while(b) {
    if(b & 1) ret = (1LL * ret * a) % p;
    a = (1LL * a * a) % p;
    b >>= 1;
  }
  return ret;
}

int discrete_log(int a, int b, int m){
  int n = (int) sqrt(m + .0) + 1;
  int an = 1;
  for(int i = 1; i <= n; i++){
    an = (1LL * an * a) % m;
  }
  unordered_map<int, int> val;
  for(int i = 1, p = an; i <= m / n + 1; i++, p = (1LL * p * an) % m){
    val[p] = i;
  }
  for(int i = 0, q = b; i <= n; i++, q = (1LL * q * a) % m){
    if(val.count(q)){
      return n * val[q] - i;
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for(int i = 0; i < 3; i++) 
    cin >> f[i];
  cin >> c;
  f[3] = (((powmod(c, 2, MOD) * 1LL * f[2]) % MOD * 1LL * f[1]) % MOD * 1LL * f[0]) % MOD;
  f[4] = (((powmod(c, 4, MOD) * 1LL * f[3]) % MOD * 1LL * f[2]) % MOD * 1LL * f[1]) % MOD;
  for(int i = 0; i < 5; i++)
    lg[i] = discrete_log(PR_MOD, f[i], MOD);
  for(int i = 0; i < 5; i++) {
    assert(powmod(PR_MOD, lg[i], MOD) == f[i]);
  }
  if(n <= 5) {
    cout << f[n - 1] << '\n';
    return 0;
  }
  magic.assign(5, vector<int>(5, 0));
  magic[0][0] = 3;
  magic[0][1] = -2;
  magic[0][3] = -1;
  magic[0][4] = 1;
  for(int i = 1; i < 5; i++)
    magic[i][i - 1] = 1;
  magic = fast_expo(magic, n - 5);
  ll ans = 0;
  for(int i = 0; i < 5; i++) {
    ans = (ans + 1LL * magic[0][i] * lg[4 - i]) % (MOD - 1);
  }
  if(ans < 0)
    ans += (MOD - 1);
  ans = powmod(PR_MOD, ans, MOD);
  cout << ans << '\n';
  return 0;
}