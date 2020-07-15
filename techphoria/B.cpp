#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define REP(i,a,b) for(int i = (int) a; i < (int) b; ++i)
#define fill(a,b) memset(a, (b), sizeof(a))
#define pii pair<int, int>
#define pll pair<long long, long long>
 
bool urut(pair<int, pii> x, pair<int, pii> y){
	return (x.ss.ss < y.ss.ss);
}
 
bool urutz(pii a, pii b){
	return (a.ff>b.ff);
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	cout.tie(NULL);
 
	int n,x;
	cin>>n;
	vector<pii> v;
	vector<pair<int, pii> > w;
	for(int i=0; i<n; i++){
		cin>>x;
		v.pb({x,i});
	}
	sort(v.begin(),v.end(),urutz );
	int j=1;
	for(auto i:v){
		w.pb({j,i});
		j++;
	}
	sort(w.begin(),w.end(),urut);
	int ans=0;
	for(auto i:w){
		ans += (i.ff-1)*i.ss.ff + 1;
	}
	cout<<ans<<"\n";
	for(auto i: v){
		cout<<i.ss+1<<" ";
	}
}