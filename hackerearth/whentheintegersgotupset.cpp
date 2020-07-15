#include <bits/stdc++.h>

using namespace std;

const int MAXN = 12;
const int INF = 2e9;
int dp[MAXN][MAXN][1<<MAXN];
int A[MAXN];
int P[MAXN];

int bit(int a){
	int res = 0;
	while(a>0){
		if(a&1) res++;
		a>>=1;
	}
	return res;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;

		if(n<=2){
			cout << 0;
			continue;
		}

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				for(int k=0; k<(1<<n); k++){
					if(i!=j && k==((1<<i)|(1<<j))){
						dp[i][j][k]=0;
					} else {
						dp[i][j][k]=INF;
					}
				}
			}
		}

		for(int i=0; i<n; i++){
			cin >> A[i];
		}
		for(int i=0; i<n; i++){
			cin >> P[i];
		}

		for(int i=0; i<(1<<n); i++){
			for(int j=0; j<n; j++){
				if(!(i&(1<<j))){
					for(int k=0; k<n; k++){
						if(i&(1<<k)){
							for(int l=0; l<n; l++){
								if(l!=k && i&(1<<l)){
									dp[j][k][i|(1<<j)] = min( dp[j][k][i|(1<<j)], dp[k][l][i]+(A[j]^A[k]^A[l])*P[bit(i)] );
								}
							}
						}
					}
				}
			}
		}

		int ans = INF;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				ans = min(ans, dp[i][j][(1<<n)-1]);
			}
		}

		cout << ans << "\n";

	}

}