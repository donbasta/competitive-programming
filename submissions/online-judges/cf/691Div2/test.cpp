#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int mod = 998244353;

int fpow(int a, int b) {
  int ret = 1;
  while (b) {
    if (b & 1) ret = 1LL * ret * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return ret;
}

int inv(int a) {
  return fpow(a, mod - 2);
}

void solve() {
  ll a = (15311432LL) * (1LL << 23) + 1;
  cout << a << '\n';
  cout << a % mod << '\n';

  int b = 62;
  int c = fpow(62, 1904);
  int ci = inv(c);
  cout << b << '\n';
  cout << c << '\n';
  cout << ci << '\n';
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