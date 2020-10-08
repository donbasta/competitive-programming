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

char solve(ll B, ll X){
	if(B==1 || X==0) return 'a';

	ll cur=0, idx=1, power=B, nextpower;

	while(idx*power+cur<=(X)){
		cur += idx*power;
		idx++;
		nextpower=B*power;
		if(nextpower/B != power) break;
		power = nextpower;
	}

	ll kata = (X+1-cur)/idx;
	ll urutan = (X+1-cur)%idx;
	if(kata==0) return 'a';
	// kata--;
	if(urutan==0) return ((char)((kata-1)%B)+97);

	vector<ll> v;
	ll i=1;
	while(i<=idx){
		v.pb(kata%B);
		kata /= B;
		i++;
	}
	reverse(v.begin(),v.end());
	return (char) (v[urutan-1]+97);


}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	cout.tie(NULL);

	ll T,B,X;
	cin >> T;
	while(T--){
		cin>>B>>X;
		cout << solve(B,X) << "\n";
	}

	// cin >> T >> B;
	// for(int i=0; i<=T; i++){
	// 	cout << solve(B,i);
	// }
	
}