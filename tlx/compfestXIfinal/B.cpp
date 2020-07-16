#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MX = 1e4;

int cnt(int a, int m) {
  return phi[m] * (a / m) + phi[a % m];
}

int cnt(int l, int r, int m) {
  return cnt(r, m) - cnt(l - 1, m);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  for(int i = 1; i <= MX; i++) {
    phi.resize(i + 1);
    phi[0] = 0;
    for(int j = 1; j <= i; j++) {
      phi[j] = phi[j - 1] + (__gcd(i, j) == 1);
    }
    //itung interval
  }

  
  return 0;
}