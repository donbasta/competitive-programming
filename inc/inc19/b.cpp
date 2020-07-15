#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define foru(i,a,b) for(int i = (int) a; i < (int) b; i++)
#define ford(i,a,b) for(int i = (int) a; i > (int) b; i--)
#define fors(i,n) for(int i = 0; i < n; i++)
#define fill(a,b) memset(a, (b), sizeof(a))
#define pii pair<int, int>
#define pll pair<long long, long long>

int dp[1004][1004];
int a[1004];

int solve(int t, int rem){
	int x;
	if(t==0 || rem==0) return 0;
	if(dp[t][rem]!=-1) return dp[t][rem];
	int ret = dp[t-1][rem];
	if(rem>=a[t]){
		int wow = solve(t-2, rem-a[t]);
		if (wow+a[t]<=rem) x = wow+a[t];
		else x = wow;
		ret = max(ret,x);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	cout.tie(NULL);

	int q,idx=1,n,k;
	cin>>q;
	while(q--){
		cin>>n>>k;
		for(int i=0; i<=k; i++) dp[0][i]=-1;
		for(int i=1; i<=n; i++){
			cin>>a[i];
			for(int j=0; j<=k; j++){
				dp[i][j]=-1;
			}
		}
		cout<<"Scenario #"<<idx<<": "<<solve(n,k)<<"\n";
	}	
}