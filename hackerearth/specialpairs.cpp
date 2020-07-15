#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

int main(){
	int tc;
	cin >> tc;
	while(tc--){

		int n;
		cin >> n;
		int A[n+1];
		int maks=0;
		map<int,int> mp;

		for(int i=1; i<=n; i++){
			cin >> A[i];
			maks = max(maks,A[i]);
			mp[A[i]]++;
		}

		int sz=0, temp=1;
		while(temp<=maks) {temp<<=1; sz++;}
		int lol = (1<<sz)-1;

		LL dp[lol+5][sz+1];
		memset(dp,0,sizeof(dp));
		
		for(int mask=0; mask<=lol; mask++){
			if(mp[mask]) dp[mask][0]=mp[mask];
			for(int j=1; j<=sz; j++){
				if(!(mask&(1<<(j-1)))) {dp[mask][j] = dp[mask][j-1];}
				else {dp[mask][j] = dp[mask][j-1]+dp[mask^(1<<(j-1))][j-1];}
			}
		}

		LL ans = 0;
		for(int i=1; i<=n; i++){
			ans += dp[lol^A[i]][sz];
		}

		cout << ans << "\n";
	}
}