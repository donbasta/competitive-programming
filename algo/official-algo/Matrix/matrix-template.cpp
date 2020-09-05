#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

template<typename T> 
struct Matrix {
  int n;
  vector<vector<T>> ve;
  Matrix(int _n) : n(_n) { ve.assign(_n, vector<T>(_n)); }
  Matrix<T> operator*(const Matrix<T>& m) const {
    Matrix<T> ret;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        for(int k = 0; k < n; k++) {
          ret.ve[i][j] = (1LL * ret.ve[i][j] + ve[i][k] * m.ve[k][j]) % MOD;
        }
      }
    }
    return ret;
  }
  // Matrix operator^(long long a) const {
  //   Matrix ret, cur(*this);
  //   for(int i = 0; i < n; i++) { ret.ve[i][i] = 1; }
  //   while(a) {
  //     if(a & 1) { ret = ret * cur; }
  //     cur = cur * cur;
  //     a >>= 1; 
  //   }
  //   return ret;
  // }
};

int main () {

  Matrix<int> A(2);
  A.ve = {{1, 1}, {1, 0}};
  Matrix<int> AA = A * A;
  // AA = A * A;
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      cout << A.ve[i][j] << ' ';
    }
    cout << '\n';
  }


}