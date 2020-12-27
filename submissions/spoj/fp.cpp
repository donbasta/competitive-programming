#include<bits/stdc++.h>
using namespace std;

string dp[105][105][15];

bool compare(string a, string b){
	int idx=0;
	while(idx<(int)a.length() && idx<(int)b.length() && a[idx]==b[idx]){
		idx++;
	}
	if(idx==(int)a.length()) return true;
	else if(idx==(int)b.length()) return false;
	else return ((int)a[idx]-'0' > (int)b[idx]-'0');
}

int mod9(string s){
	int ans=0;
	for(auto i : s){
		ans += (int) i-'0';
		ans %= 9;
	}
	return ans;
}

string maks(string a, string b){
	if(a.length() > b.length()) return a;
	else if (a.length() < b.length()) return b;
	else {
		int idx=0;
		while(idx<(int)a.length() && a[idx]==b[idx]) idx++;
		if(idx==(int)a.length()) return b;
		else if((int)a[idx]-'0' < (int)b[idx]-'0') return b;
		else return a;
	}
}

int main(){
	string s;
	// string t;
	// cin >> s >> t;
	// if(compare(s,t)) cout << "true";
	// else cout << "false";
	int T,n,k; cin >> T;
	while(T--){
		vector<string> v;
		cin >> n >> k;
		int t[n+5];
		for(int i=1; i<=n; i++) {cin >> s; v.push_back(s);}
		sort(v.begin(), v.end(), compare);
		// for(auto i : v) cout << i << " "; cout << "\n";
		int j=1;
		for(auto i:v){
			t[j] = mod9(i); j++;
		}

		for(int i=0; i<=n; i++){
			for(int j=0; j<=k; j++){
				for(int res=0; res<9; res++)
					dp[i][j][res]="";
			}
		}

		for(int i=1; i<=n; i++){
			for(int j=1; j<=k; j++){
				for(int res=0; res<9; res++){
					if(dp[i-1][j-1][(res-t[i]+9)%9]=="" && j>1) dp[i][j][res] = dp[i-1][j][res];
					// else if(dp[i-1][j-1][(res-t[i]+9)%9]=="" && j==1) {if((res-t[i]+9)%9==0) dp[i][j][res]=v[i-1];}
					else if(mod9(dp[i-1][j-1][(res-t[i]+9)%9])==(res-t[i]+9)%9) dp[i][j][res] = maks(dp[i-1][j][res], dp[i-1][j-1][(res-t[i]+9)%9]+v[i-1] ); 
					else dp[i][j][res] = dp[i-1][j][res];
				}
			}
		}
		if(dp[n][k][0].length()==0) cout << -1 << "\n";
		else cout << dp[n][k][0] << "\n";
	}

}