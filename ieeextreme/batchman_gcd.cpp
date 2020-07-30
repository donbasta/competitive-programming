#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD[] = {1000000007, 998244353};
const int N = 1e5;

int ans[2][N + 69], pw[2][N + 69];
int ar[N + 69], cnt[N + 69];
int n, k;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
  	cin >> ar[i];
  	for(int j = 1; j * j <= ar[i]; j++) {
  		if(ar[i] % j == 0) {
  			cnt[j]++;
  			if(j * j != ar[i])
  				cnt[ar[i] / j]++;
  		}
  	}
  }
  pw[0][0] = pw[1][0] = 1;
  for(int i = 1; i <= N; i++) {
  	pw[0][i] = (1LL * 2 * pw[0][i - 1]) % MOD[0];
  	pw[1][i] = (1LL * 2 * pw[1][i - 1]) % MOD[1];
  }
  int jwb = 0;
  for(int i = N; i >= 1; i--) {
  	bool ok = true;
  	for(int t = 0; t < 2; t++) {
  		int lol = (pw[t][min(cnt[i], k)] - 1);
  		for(int j = 2 * i; j <= N; j += i) {
  			lol = (1LL * lol - ans[t][j]) % MOD[t];
  		}
  		if(lol < 0)
  			lol += MOD[t];
  		ans[t][i] = lol;
  		ok &= (lol == 0);
  	}
  	jwb += ok;
  }
  cout << N - jwb << '\n';
  return 0;
}