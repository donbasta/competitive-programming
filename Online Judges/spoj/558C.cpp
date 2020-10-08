#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int maxn = 1e5;

int n;
int cnt[maxn+5], vis[maxn+5];
long long mv[maxn+5];

int main(){
 ios_base::sync_with_stdio(0);
 cin.tie(0), cout.tie(0);

 cin >> n;
 for(int i=1; i<=n; i++){
 	int x;
 	cin >> x;
 	queue<pair<int,int>> q;
 	q.push({x,0});
 	vis[x] = i;
 	while(!q.empty()){
 		int a = q.front().first;
 		int b = q.front().second;
 		mv[a] += 1ll * b;
 		cnt[a]++;
 		q.pop();
 		if(vis[a/2] != i) {
 			q.push({a/2, b+1});
 			vis[a/2] = i;
 		}
 		if(vis[a*2] != i && a*2 <= maxn) {
 			q.push({a*2, b+1});
 			vis[a*2] = i;
 		}
 	}
 }

 long long ans = INF;
 for(int i=0; i<=maxn; i++){
 	if(cnt[i]==n){
 		// cerr << i << " " << mv[i] << "\n";
 		ans = min(ans, mv[i]);
 	}
 }

 cout << ans;

}