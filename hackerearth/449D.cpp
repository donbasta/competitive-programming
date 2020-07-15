#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

const LL MOD = 1e9+7;
const int mask = (1<<20)-1;

int dp[mask+1][21];

LL powmod(LL a, LL b){
	LL res = 1;
	while(b > 0){
		if(b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int bits(int x){
	int res = 0;
	while(x > 0){
		if(x&1) res++; 
		x >>= 1;
	}
	return res;
}

int main(){

	int n;
	cin >> n;
	
	int x;
	for(int i=1; i<=n; i++){
		cin >> x;
		dp[x^mask][0]++;
	}

	for(int i=0; i<=mask; i++){
		for(int j=0; j<20; j++){
			if(!(i&(1<<j))){
				dp[i][j+1] = dp[i][j];
			} else {
				dp[i][j+1] = dp[i^(1<<j)][j] + dp[i][j];
			}
			dp[i][j+1] %= (MOD-1);
		}
	}

	LL ans = 0;
	for(int i=0; i<=mask; i++){
		if(bits(i)&1){
			ans -= (powmod(2,dp[i^mask][20]) - 1);
		} else {
			ans += (powmod(2,dp[i^mask][20]) - 1);
		}
		ans = ((ans%MOD)+MOD)%MOD;
	}

	cout << ans;

}