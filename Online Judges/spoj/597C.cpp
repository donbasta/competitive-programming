#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int MAXN = 1e5+5;

int N,K;
LL bit[MAXN][12];
LL dp[MAXN][12];

void upd1(int a, int M){
	int a1 = a-1;
	dp[a][M] = 0;
	for(; a1>0; a1 -= a1&-a1){
		dp[a][M] += bit[a1][M-1];
	}
}

void upd2(int a, int M){
	int a1 = a;
	LL pre = dp[a][M];
	upd1(a,M);
	LL post = dp[a][M];
	for(; a1 <= N; a1 += a1&-a1){
		bit[a1][M] += post-pre;
	}
}

int main(){

	ios_base::sync_with_stdio(false); cin.tie(); cout.tie();

	cin >> N >> K;

	int x, x1;
	for(int i=1; i<=N; i++){
		cin >> x;
		x1 = x;
		dp[x][0] = 1;
		while(x1<=N){
			bit[x1][0]++;
			x1 += x1&-x1;
		}
		for(int j=1; j<=K; j++){
			upd2(x,j);
		}
	}

	LL ans = 0;
	for(int i=1; i<=N; i++){
		ans += dp[i][K];
	}
	cout << ans;

}