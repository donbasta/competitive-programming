#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using matrix = vector<vector<ll>>;

const ll MOD = 1e9 + 7;
ll n;

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
 
matrix fast_expo(matrix a, ll b){
  int sz = (int)a.size();
  matrix ret(sz, vector<ll>(sz));
  for(int i = 0; i < sz; i++) ret[i][i] = 1;
  while(b) {
    if(b & 1) ret = mul(ret, a, sz);
    a = mul(a, a, sz);
    b >>= 1;
  }
  return ret;
}

void solve() {
  matrix magic = {{1,1,1,1,1,1},{1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,0,0},{0,0,0,0,1,0}};
  vector<ll> init = {0,1,2,4,8,16,32};
  cin >> n;
  if(n <= 6) {cout << init[n] << '\n'; return;}
  magic = fast_expo(magic, n - 6);
  ll ans = 0;
  for(int i = 0; i < 6; i++) {
    ans = (ans + magic[0][i] * init[6 - i]) % MOD;
  }
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