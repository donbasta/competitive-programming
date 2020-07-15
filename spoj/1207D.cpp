#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 3e5+5;
const int MOD = 998244353;

int n,a,b;
int m1[MAXN],m2[MAXN];
map<pair<int, int>, int> m3;
vector<pair<int,int> > v; 
LL ans, cur;
LL fac[MAXN];

void precomp(){
	fac[0]=1;
	for(int i=1; i<MAXN; i++){
		fac[i] = i*fac[i-1]%MOD;
	}
}

bool comp(pair<int, int> a, pair<int, int> b){
	return (a.first<b.first) || ((a.first==b.first) && (a.second < b.second));
}

int main(){

	precomp();

	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a >> b;
		m1[a]++;
		m2[b]++;
		m3[{a,b}]++;
		v.push_back({a,b});
	}

	cur = 1;
	for(int i=1; i<=n; i++){
		cur *= fac[m1[i]];
		cur %= MOD;
	}
	ans = cur;
	cur = 1;
	for(int i=1; i<=n; i++){
		cur *= fac[m2[i]];
		cur %= MOD;
	}
	ans += cur;
	ans %= MOD;
	cur = 1;

	sort(v.begin(),v.end(),comp);
	bool nd = true;
	int prev_a = v[0].first;
	int prev_b = v[0].second;
	int i=1;
	while(nd && i<n){
		if(v[i].first<prev_a) nd=false;
		if(v[i].second<prev_b) nd=false;
		prev_a = v[i].first;
		prev_b = v[i].second;
		i++;
	}

	for(auto i : m3){
		cur *= fac[i.second];
		cur %= MOD;
	}
	if(nd) ans -= cur;
	ans = (ans+MOD)%MOD;
	ans = (fac[n]-ans)%MOD;
	if(ans<0) ans+= MOD;

	cout << ans;

}