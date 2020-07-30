#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;
// const int SZ = 2;

typedef vector<vector<ll>> matrix;
matrix identity = {{1, 0}, {0, 1}};
matrix magic;
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
  int sz = (int) a.size();
  if(b == 0) return identity; //define identity first
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

  cin >> n;
  magic = {{1, 1}, {1, 0}};
  magic = fast_expo(magic, n);
  ll ans = (magic[1][0]) % MOD;
  if(ans < 0)
    ans += MOD;
  cout << ans << '\n';

}
