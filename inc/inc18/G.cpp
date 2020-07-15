#include <bits/stdc++.h>
using namespace std;

const int N = 16;

int n;
long long x[N], y[N];
long double dp[1 << N][N];

long double dist(int a, int b) {
	int da = x[a] - x[b];
	int db = y[a] - y[b];
	long double res = hypot(da, db);
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	for(int i = 0; i < (1 << n); i++) {
		for(int j = 0; j < n; j++) {
			if((i) & (1 << j)) {
				long double temp = 1e18;
				int k = i ^ (1 << j);
				int cnt_k = __builtin_popcount(k);
				for(int l = 0; l < n; l++) {
					if(l == j)
						continue;
					if(!(k & (1 << l)))
						continue;
					temp = min(temp, dp[k][l] + ((long double) (cnt_k)) * dist(l, j));
				}
				if(temp == 1e18)
					dp[i][j] = 0;
				else
					dp[i][j] = temp;
			}
		}
	}

	long double ans = 1e18;
	for(int i = 0; i < n; i++) {
		ans = min(ans, dp[(1 << n) - 1][i]);
	}

	cout << fixed << setprecision(12) << ans << "\n";
	return 0;
}