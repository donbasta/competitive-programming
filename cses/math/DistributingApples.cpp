#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e6;
const int MOD = 1e9 + 7;

int fc[N + 5], ifc[N + 5];

int fastexp(int a, int b) {
  int ret = 1;
  while(b) {
    if(b & 1) ret = 1LL * ret * a % MOD;
    a = 1LL * a * a % MOD;
    b >>= 1;
  }
  return ret;
}

int inv(int a) {
  return fastexp(a, MOD - 2);
}

void init() {
  fc[0] = 1;
  for(int i = 1; i <= N; i++) {
    fc[i] = 1LL * i * fc[i - 1] % MOD;
  }
  ifc[N] = inv(fc[N]);
  for(int i = N - 1; i >= 0; i--) {
    ifc[i] = 1LL * (i + 1) * ifc[i + 1] % MOD;
  }
}

int C(int a, int b) {
  int ret = fc[a];
  ret = 1LL * ret * ifc[b] % MOD;
  ret = 1LL * ret * ifc[a - b] % MOD;
  return ret;
}

void solve() {
  int n, m;
  cin >> n >> m;
  cout << C(m + n - 1, n - 1) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  init();
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}