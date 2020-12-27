#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;
// const int SZ = 2;

typedef vector<vector<ll>> matrix;
matrix magic, identity;
ll n, k, p ,q, r;
vector<ll> ar, c;

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
  int sz = (int) a.size();
  // if(b == 0) return identity; //define identity first
  if(b == 1) return a;
  if(b % 2 == 1) return mul(a, fast_expo(a, b - 1), sz);
  matrix c = fast_expo(a, b/2);
  return mul(c, c, sz);
}

void printMatrix(matrix a) {
  for(auto baris : a) {
    for(auto kotak : baris) {
      cout << kotak << " ";
    }
    cout << "\n";
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> n >> k;
  ar.resize(n + 5), c.resize(n + 5);
  for(int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  for(int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  c[0] = -1;
  cin >> p >> q >> r;
  for(int i = n; i <= n + 1; i++) {
    for(int j = 1; j <= n; j++) {
      ar[i] = (ar[i] + c[j] * ar[i - j]) % MOD;
    }
    ar[i] = (ar[i] + p + i * q + i * i * r) % MOD;
  }
  magic.assign(n + 3, vector<ll>(n + 3, 0));
  identity.assign(n + 3, vector<ll>(n + 3, 0));
  for(int i = 0; i < n + 3; i++) {
    identity[i][i] = 1;
  }
  for(int i = 1; i <= n + 1; i++) {
    magic[i][i - 1] = 1;
  }
  magic[n + 2][n + 2] = 1;
  magic[0][0] = c[1] + 2;
  for(int i = 1; i < n + 2; i++) {
    magic[0][i] += c[i + 1];
    magic[0][i] -= 2 * c[i];
    magic[0][i] += c[i - 1];
  }
  magic[0][n + 2] = 2;
  if(k <= n + 1) {
    cout << ar[k] << '\n';
    return 0;
  }
  magic = fast_expo(magic, k - 2);
  ll ans = 0;
  vector<ll> lol(n + 3);
  for(int i = 0; i < n + 2; i++) {
    lol[i] = ar[n + 1 - i];
  }
  lol[n + 2] = r;
  for(int i = 0; i < n + 3; i++) {
    // cerr << i << ' ' << ans << '\n';
    ans = (ans + magic[0][i] * lol[i]) % MOD;
  }
  if(ans < 0)
    ans += MOD;
  cout << ans << '\n';

}
