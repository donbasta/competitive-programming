#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;
string In, Out;

typedef vector<vector<int>> matrix;

matrix mul(matrix a, matrix b, int sz){
  matrix d(sz, vector<int>(sz));
  for(int i = 0; i < sz; i++) {
    for(int j = 0; j < sz; j++) {
      for(int k = 0; k < sz; k++) {
        d[i][j] = (d[i][j] + a[i][k] * b[k][j]);
      }
      if(d[i][j] > 0) d[i][j] = 1;
    }
  }
  return d;
}
 
matrix expo(matrix a, int b){
  int sz = (int) a.size();
  if(b == 1) return a;
  if(b % 2 == 1) return mul(a, expo(a, b - 1), sz);
  matrix c = expo(a, b / 2);
  return mul(c, c, sz);
}

void solve() {
  cin >> n;
  cin >> In >> Out;
  matrix magic(n, vector<int>(n));
  vector<vector<char>> ans(n, vector<char>(n, 'N'));
  for(int i = 0; i < n; i++)
    magic[i][i] = 1;
  for(int i = 0; i < n - 1; i++) {
    if(In[i] == 'Y' && Out[i + 1] == 'Y')
      magic[i + 1][i] = 1;
    if(In[i + 1] == 'Y' && Out[i] == 'Y')
      magic[i][i + 1] = 1;
  }
  magic = expo(magic, n + 1);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++) {
      if(i == j) ans[i][j] = 'Y';
      if(magic[i][j] > 0) ans[i][j] = 'Y';
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++) {
      cout << ans[i][j];
    }
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    cout << "Case #" << i << ":\n";
    solve();
  }
  
  return 0;
}