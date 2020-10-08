#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;
const int M = 1e9;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cout << N << '\n';
  for(int i = 0; i < N; i++) {
    cout << rand() % M + 1 << ' ';
  }
  
  return 0;
}