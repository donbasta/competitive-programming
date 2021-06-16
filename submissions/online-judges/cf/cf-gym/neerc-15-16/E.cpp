#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 18;
const int M = 1 << N;
const ll MOD = 1e9 + 7;

ll fact[M + 5], ifact[M + 5];
ll ar[M + 5];
ll A[M + 5], B[M + 5];
int k, n;

ll fastexpo(ll a, ll b) {
  ll ret = 1;
  while(b) {
    if(b & 1) ret = ret * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return ret;
}

ll inv(ll a) {
  return fastexpo(a, MOD - 2);
}

void init() {
  fact[0] = 1;
  for(int i = 1; i <= M; i++) {
    fact[i] = fact[i - 1] * i % MOD;
  }
  ifact[M] = inv(fact[M]);
  for(int i = M - 1; i >= 0; i--) {
    ifact[i] = ifact[i + 1] * (i + 1) % MOD;
  }
}

ll C(ll a, ll b) {
  if(a < b || a < 0 || b < 0) return 0;
  ll ret = fact[a];
  ret = ret * ifact[a - b] % MOD;
  ret = ret * ifact[b] % MOD;
  return ret;
}

void solve() {
  init();
  cin >> k;
  n = (1 << k);
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  ll ans = 0;
  for(int j = 0; j < k; j++) {
    for(int i = 1; i <= n; i++) {
      ll koef = (1LL << (j + 1));
      ll temp = (1LL << (k - j - 1));
      koef = koef * fact[n - 2 * temp] % MOD;
      koef = koef * C(n - i, temp - 1) % MOD;
      koef = koef * fact[temp] % MOD;
      koef = koef * fact[temp] % MOD;
      A[i] = koef * ar[i] % MOD;
    }
    for(int i = 1; i <= n; i++) {
      ll koef = 1;
      ll temp = (1LL << (k - j - 1));
      koef = koef * C(n - i - temp, temp - 1) % MOD;
      B[i] = koef * ar[i] % MOD;
    }
    ll sum = 0;
    ll cur = B[1];
    for(int i = 2; i <= n; i++) {
      sum = (sum + A[i] * cur) % MOD;
      cur = (cur + B[i]) % MOD;
    }
    ans = ans + sum % MOD;
  }
  ans = ans * ifact[n] % MOD;
  if(ans < 0) ans += MOD;
  cout << ans << '\n';
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