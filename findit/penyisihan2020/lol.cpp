#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll powmod(ll a, ll b){
	ll res = 1;
	while(b>0){
		if(b&1) res = res * a % 100;
		a = a * a % 100;
		b >>= 1;
	}
	return res;
}

ll f(ll a, ll b){
	if(b==0) return 1;
	return powmod(a, f(a, b-1));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 3;
	
	while(t--){
		ll x, y;
		cin >> x >> y;
		cerr << f(x,y) << "\n";
	}

}
