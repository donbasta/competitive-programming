#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const int SZ = 2;

typedef vector<vector<ld>> matrix;
matrix identity = {{1.0, 0.0}, {0.0, 1.0}};
matrix magic;
ld p;
ll n;

matrix mul(matrix a, matrix b, int sz = SZ){
  matrix d(sz, vector<ld>(sz));
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
  if(b == 0) return identity; //define identity first
  if(b == 1) return a;
  if(b % 2 == 1) return mul(a, fast_expo(a, b - 1));
  matrix c = fast_expo(a, b / 2);
  return mul(c, c);
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

  cin >> n >> p;
  magic = {{1.0 - 2.0 * p, p}, {0.0, 1.0}};
  magic = fast_expo(magic, n);
  ld ans = magic[0][0] + magic[0][1];
  cout << fixed << setprecision(12) << ans << '\n';


}
