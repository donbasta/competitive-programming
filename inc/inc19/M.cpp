#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;
const int N = 2e5 + 69;

int n, m;
ll fac[N], ifac[N];

ll modpow(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b & 1) {res = res * a % MOD;}
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

ll C(ll a, ll b){
	if(a < b || a < 0 || b < 0)
		return 0;
	ll atas = fac[a];
	ll bawah = ifac[b] * ifac[a - b] % MOD;
	ll ans = atas * bawah % MOD;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	fac[0] = 1;
	for(int i = 1; i <= 200000; i++) {
		fac[i] = fac[i - 1] * i % MOD;
	}
	ifac[200000] = modpow(fac[200000], MOD - 2);
	for(int i = 199999; i >= 0; i--) {
		ifac[i] = ifac[i + 1] * (i + 1) % MOD;
	}

	cin >> n >> m;
	ll sgn = 1, ans = 0;
	for(int i = 0; 3 * i <= n; i++) {
		ll temp = sgn * C(m + 1, i) * C(m + n - 3 * i, m) % MOD;
		ans = (ans + temp) % MOD;
		sgn = -sgn;
	}
	ans = (ans % MOD);
	if(ans < 0)
		ans += MOD;
	cout << ans << "\n";
	return 0;
}