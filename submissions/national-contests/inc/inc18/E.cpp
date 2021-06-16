#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 69;

int n;
int s[N];
int cnt[10];
int dp[N][10], dp11[N][10], dp22[N][10];
int dp1[N];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
		cnt[s[i]]++;
	}

	int mx = 0;
	for(int i = 0; i < 10; i++) {
		mx = max(mx, cnt[i]);
	}
	int superb = n - mx;

	for(int i = 0; i < 10; i++) {
		dp[1][i] = (s[1] != i);
	}
	for(int i = 2; i <= n; i++) {
		for(int j = 0; j < 10; j++) {
			int temp = dp[i - 1][j];
			if(j > 0)
				temp = min(temp, dp[i - 1][j - 1]);
			if(j < 9)
				temp = min(temp, dp[i - 1][j + 1]);
			dp[i][j] = (s[i] != j) + temp;
		}
	}
	int great = 1e9;
	for(int i = 0; i < 10; i++) {
		great = min(great, dp[n][i]);
	}


	for(int i = 1; i <= min(n, 5); i++) {
		int temp = 1e9;
		for(int j = 0; j < 10; j++) {
			dp11[i][j] = 1e9;
			dp22[i][j] = 1e9;
			temp = min(temp, dp[i][j]);
			if(i >= 4)
				dp11[i][j] = dp1[i - 1] + (s[i] != j);
			if(i >= 5){
				dp22[i][j] = dp1[i - 2] + (s[i] != j) + (s[i - 1] != j);
				if(j > 0)
					dp22[i][j] = min(dp22[i][j], dp1[i - 2] + (s[i] != j) + (s[i - 1] != j - 1));
				if(j < 9)
					dp22[i][j] = min(dp22[i][j], dp1[i - 2] + (s[i] != j) + (s[i - 1] != j + 1));
			}
		}
		dp1[i] = temp;
	}

	for(int i = 6; i <= n; i++) {
		dp1[i] = 1e9;
		for(int j = 0; j < 10; j++) {
			dp11[i][j] = dp1[i - 1] + (s[i] != j);
			for(int k = j - 1; k <= j + 1; k++) {
				if(k < 0 || k > 9)
					continue;
				int cur1 = (s[i - 1] != k) + (s[i] != j);
				dp22[i][j] = min(dp22[i][j], dp1[i - 2] + cur1);
				for(int l = k - 1; l <= k + 1; l++) {
					if(l < 0 || l > 9)
						continue;
					int cur = (s[i - 2] != l) + (s[i - 1] != k) + (s[i] != j);
					if(l > 0){
						dp1[i] = min(dp1[i], cur + dp11[i - 3][l - 1]);
						dp1[i] = min(dp1[i], cur + dp22[i - 3][l - 1]);
					}
					dp1[i] = min(dp1[i], cur + dp11[i - 3][l]);
					dp1[i] = min(dp1[i], cur + dp22[i - 3][l]);
					if(l < 9) {
						dp1[i] = min(dp1[i], cur + dp11[i - 3][l + 1]);
						dp1[i] = min(dp1[i], cur + dp22[i - 3][l + 1]);
					}
					dp1[i] = min(dp1[i], cur + dp1[i - 3]);
				}
			}
		}
	}

	int good = dp1[n];

	cout << good << " " << great << " " << superb << "\n";
	return 0;
}