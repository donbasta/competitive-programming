#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using matrix = vector<vector<ll>>;

const ll MOD = 1000000007;

matrix M;
ll n, m, x;

matrix mul(matrix a, matrix b) {
  matrix res(m, vector<ll>(m));
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < m; j++) {
      for(int k = 0; k < m; k++) {
        res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
      }
    }
  }
  return res;
}

matrix fastpow(matrix a, ll b) {
  if(b == 1) return a;
  if(b & 1) return mul(a, fastpow(a, b - 1));
  matrix res = fastpow(a, b / 2);
  return mul(res, res);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n >> m;

  vector<ll> temp;
  temp.push_back(1);
  for(int i = 1; i <= m - 2; i++)
    temp.push_back(0);
  temp.push_back(1);
  M.push_back(temp);
  temp.clear();
  for(int i = 1; i < m; i++) {
    for(int j = 1; j <= m; j++) {
      if(j == i) temp.push_back(1);
      else temp.push_back(0);
    }
    M.push_back(temp);
    temp.clear();
  }

  if(n < m) {cout << 1 << '\n'; return 0;}
  if(n == m) {cout << 2 << '\n'; return 0;}
  M = fastpow(M, n - m);

  ll res = 0;
  for(int i = 0; i < m; i++) {
    if(!i) {
      res += 2 * M[0][i];
    } else {
      res += M[0][i];
    }
    res %= MOD;
  }
  cout << res << '\n';
  return 0;
}
