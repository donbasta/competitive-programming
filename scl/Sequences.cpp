#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

typedef vector<vector<ll>> matrix;

const int N = 5e3 + 10, K = 2e3 + 10;
const ll MOD = 1e9 + 7;

matrix mat;
ll n, m, k;
ll cnt[N];

void process(ll a, ll b, ll c){
    for (ll j=1;j<=min(k, c);j++){
        ll temp = (a * j * j % k + b) % k;
        ll isi = (c - j) / k + 1LL;
        cnt[temp] = (cnt[temp] + isi) % MOD;
        // cout << temp << ":" << isi << " ";
    }
    // cout << el;
}

matrix mul(matrix a, matrix b, int sz){
  matrix d(sz, vector<ll>(sz));
  for(int i = 0; i < sz; i++) {
    for(int j = 0; j < sz; j++) {
      for(int k = 0; k < sz; k++) {
        d[i][j] = (d[i][j] + a[i][k] * b[k][j]);
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

void printMatrix(matrix a) {
  for(auto baris : a) {
    for(auto kotak : baris) {
      cout << kotak << " ";
    }
    cout << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n >> m >> k;
  for (ll i=1;i<=n;i++){
      ll a, b, c;
      cin >> a >> b >> c;
      process(a, b, c);
  }

  mat.assign(k, vector<ll>(k));
  for(int i = 0; i < k; i++) {
    for(int j = 0; j < k; j++) {
      mat[i][j] = cnt[(i + k - j) % k];
      // mat[i][j] = (i + k - j) % k;
    }
  }

  // printMatrix(mat);

  if(m == 1) {
    cout << cnt[0] << '\n';
    return 0;
  }

  mat = fast_expo(mat, m - 1);
  ll ans = 0;
  for(int i = 0; i < k; i++) {
    ans += 1LL * mat[0][i] * cnt[i];
  }
  ans = ((ans % MOD) + MOD) % MOD;
  cout << ans << '\n';
  return 0;
}
