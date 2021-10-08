#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100;

ll n, h;

void solve() {
    cin >> n >> h;

    vector<ll> p(n + 1), v(n + 1);
    vector<vector<ll>> dp(n + 1, vector<ll>(n * N + 1, -1));
    for (int i = 1; i <= n; i++) {
    	cin >> p[i] >> v[i];
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
    	for (int j = 0; j <= i * N; j++) {
	    	ll cur_val = v[i];
	    	ll tmp = -1;
	    	if (dp[i - 1][j] != -1) {
	    		tmp = dp[i - 1][j];
	    	}
	    	ll pwr = p[i];
	    	ll dmg = pwr;
	    	ll loss = v[i] - (cur_val / 2);
	    	while (cur_val && (loss <= j)) {
	    		if (dp[i - 1][j - loss] != -1) {
	    			tmp = max(tmp, dmg + dp[i - 1][j - loss]);
	    		}
	    		pwr *= 2;
	    		dmg += pwr;
	    		cur_val /= 2;
	    		loss = v[i] - (cur_val / 2);
	    	}
	 		dp[i][j] = tmp;
    	}
    }
    for (int i = 0; i <= n * N; i++) {
    	if (dp[n][i] >= h) {
    		cout << i << '\n';
    		return;
    	}
    }
    cout << -1 << '\n';
    return;
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