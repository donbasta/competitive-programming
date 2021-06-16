#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5;

int n;
int divisor[N + 69];

long long modpow(long long a, long long b) {
	long long ret = 1;
	while(b) {
		if(b & 1) {ret = ret * a % MOD;}
		a = a * a % MOD;
		b >>= 1;
	}
	return ret;
}

long long inv(long long a) {
	return modpow(a, MOD - 2);
}

void sieve() {
	for(int i = 1; i <= N; i++) {
		for(int j = i; j <= N; j += i) {
			divisor[j]++;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	sieve();

	cin >> n;
	long long ans = 0;
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		int t = divisor[i];
		ans = ans + (1LL * x * (n - t) % MOD) * inv(t + 1);
		ans = ans % MOD;
	}

	cout << ans << "\n";
	return 0;

}
