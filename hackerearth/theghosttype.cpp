#include <bits/stdc++.h>
#define pb push_back

typedef long long LL;

using namespace std;

const int MAXN = 21;

LL dp[1<<(MAXN-1)];
vector<int> ve[MAXN];

int main(){

	int N;
	cin >> N;

	for(int i=0; i<N; i++){
		dp[1<<i] = 1;
	}

	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if((i&j)==i){
				ve[i-1].pb(j-1);
			}
		}
	}

	for(int i=0; i<(1<<N); i++){
		for(int j=0; j<N; j++){
			if(!(i&(1<<j))){
				bool bisa = true;
				for(int k : ve[j]){
					if(i&(1<<k)){
						bisa = false; break;
					}
				}
				if(bisa) dp[i|(1<<j)] += dp[i];
			}
		}
	}

	cout << dp[(1<<N)-1];

}