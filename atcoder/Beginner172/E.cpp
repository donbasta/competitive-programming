#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 5e5 + 69;
const ll MOD = 1e9 + 7;

ll ans = 0;
ll fac[N + 10], ifac[N];
int n, m;

ll binpow(ll a, ll b) {
	ll ret = 1;
	while(b) {
		if(b & 1) {ret = (ret * a) % MOD;}
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}

void init() {
	fac[0] = 1;
	for(int i = 1; i <= N; i++) {
		fac[i] = (1LL * i * fac[i - 1]) % MOD;
	}
	ifac[N] = binpow(fac[N], MOD - 2);
	for(int i = N - 1; i >= 0; i--) {
		ifac[i] = (1LL * (i + 1) * ifac[i + 1]) % MOD;
	}
}

ll C(ll a, ll b) {
	if(a < b || a < 0 || b < 0)
		return 0;
	ll temp = (fac[a] * ifac[a - b]) % MOD;
	temp = (temp * ifac[b]) % MOD;
	return temp;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  init();
  cin >> n >> m;
  // int start = max(0, 2 * n - m);
  // for(int i = start; i <= n; i++) {
  // 	ll temp = 1;
  // 	temp = (temp * ifac[n - i]) % MOD;
  // 	temp = (temp * ifac[n - i]) % MOD;
  // 	temp = (temp * ifac[i]) % MOD;
  // 	temp = (temp * ifac[m - 2 * n + i]) % MOD;
  // 	ans = (ans + temp) % MOD;
  // }
  // ans = (ans * fac[n]) % MOD;
  // ans = (ans * fac[n]) % MOD;
  // ans = (ans * fac[m]) % MOD;
  // cout << ans << '\n';
  ll sgn = 1;
  ll cur = (fac[m] * ifac[m - n]) % MOD;
  for(int i = 0; i <= n; i++) {
  	ll temp = sgn;
  	temp = (temp * cur) % MOD;
  	temp = (temp * fac[m - i]) % MOD;
  	temp = (temp * ifac[m - n]) % MOD;
  	temp = (temp * C(n, i)) % MOD;
  	ans = (ans + temp) % MOD;
  	sgn = -sgn;
  }
  ans = ((ans % MOD) + MOD) % MOD;
  cout << ans << '\n';

  return 0;
}
