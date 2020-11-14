#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int M = 150000;
const ll MOD = 998244353;

ll fc[2*M + 5], ifc[2*M + 5];

ll fastExpo(ll a, ll b) {
  ll ret = 1;
  while(b) {
    if (b & 1) ret = ret * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return ret;
}

ll inv(ll a) {
  return fastExpo(a, MOD-2);
}

void initFac() {
  fc[0] = 1;
  for (int i = 1; i <= 2*M; i++) {
    fc[i] = fc[i - 1] * i % MOD;
  }
  ifc[2*M] = inv(fc[2*M]);
  for (int i = 2*M - 1; i >= 0; i--) {
    ifc[i] = ifc[i + 1] * (i + 1) % MOD;
  }
}

ll C(ll a, ll b) {
  ll ret = fc[a];
  ret = ret * ifc[b] % MOD;
  ret = ret * ifc[a-b] % MOD;
  return ret;
}

void solve() {
  initFac();

  int n;
  cin >> n;
  vector<int> ve;
  for (int i = 0; i < 2*n; i++) {
    int x;
    cin >> x;
    ve.emplace_back(x);
  }
  sort(ve.begin(), ve.end());
  ll tes = 0;
  for (int i = 0; i < n; i++) {
    tes += 1LL * (ve[2*n - 1 - i] - ve[i]);
  }
  tes %= MOD;
  tes = tes * C(2*n, n) % MOD;
  if (tes < 0) tes += MOD;
  cout << tes << '\n';
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