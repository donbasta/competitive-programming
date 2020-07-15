#include <bits/stdc++.h>
     
using namespace std;    
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
#define endl "\n"

const int MAXN = 1e5+5;

int n,m;
int timer;
int tin[MAXN], low[MAXN];
vector<int> adj[MAXN];
set<int> bridge;
map<pii,int> mm;
bool vis[MAXN];
pii edge[5*MAXN];


void dfs1(int v, int par=0){
	vis[v] = true;
	low[v] = tin[v] = timer++;
	for(auto i : adj[v]){
		if(i==par) continue;
		else if(vis[i]){
			low[v] = min(low[v],tin[i]);
		} else {
			dfs1(i,v);
			low[v] = min(low[v],low[i]);
			if(low[i]>tin[v]){
				bridge.insert(mm[{v,i}]);
			}
		}
	}
}	

void findbridge(){
	timer = 0;
	memset(tin, -1, sizeof(tin));
	memset(low, -1, sizeof(low));
	dfs1(1);
}

ll dfs2(int v){
	ll ret = 1;
	vis[v] = true;
	for(auto i : adj[v]){
		if(!vis[i]){
			vis[i] = true;
			ret += dfs2(i);
		}
	}
	return ret;
}

void clearbridge(){
	for(int i=1; i<=n; i++){
		adj[i].clear();
	}
	for(int i=1; i<=m; i++){
		if(bridge.find(i)==bridge.end()){
			int f = edge[i].ff;
			int s = edge[i].ss;
			adj[f].pb(s);
			adj[s].pb(f);
		}
	}
}

int countpart(){
	memset(vis, false, sizeof(vis));
	ll ans = 0, x;
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			vis[i] = true;
			x = dfs2(i);
			ans += x*(x-1)/2;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(); cout.tie();

	cin >> n >> m;
	int a,b;
	for(int i=1; i<=m; i++){
		cin >> a >> b;
		mm[{a,b}] = i;
		mm[{b,a}] = i;
		edge[i] = {a,b};
		adj[a].pb(b);
		adj[b].pb(a);
	}

	findbridge();
	clearbridge();

	ld ans = countpart();
	ll lol = 1ll*n*(n-1)/2;
	ld l = lol;
	cout << fixed << setprecision(5) << ans/l;
	
}
