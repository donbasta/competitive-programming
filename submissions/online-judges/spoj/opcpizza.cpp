#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int t; scanf("%d", &t);
	ll n, k, x;
	while(t--){
		map<ll,ll> m;
		scanf("%lld %lld", &n, &k);
		for(int i=0; i<n; i++){
			cin >> x; m[x]++;
		}
		ll ans = 0;
		for(auto i : m){
			ll t = i.second;
			ll r = min(t, m[k - (i.first)]);
			ans += r; 
			i.second -= r;
			m[k-(i.first)] -= r;
		}
		printf("%lld\n", ans);
	}
}