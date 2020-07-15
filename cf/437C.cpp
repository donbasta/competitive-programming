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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	cout.tie(NULL);

	int val[1005];
	int n,m,x,y;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>val[i];
	}
	int ans=0;
	for(int i=1; i<=m; i++){
		cin>>x>>y;
		ans += min(val[x],val[y]);
	}

	cout<<ans;
}