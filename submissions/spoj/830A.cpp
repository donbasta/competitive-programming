#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main(){
 ios_base::sync_with_stdio(0);
 cin.tie(0), cout.tie(0);

 int n,k,p;
 cin >> n >> k >> p;
 int orang[n+5];
 int kunci[k+5];

 for(int i=1; i<=n; i++){
 	cin >> orang[i];
 }
 for(int i=1; i<=k; i++){
 	cin >> kunci[i];
 }
 sort(orang+1, orang+n+1);
 sort(kunci+1, kunci+k+1);

 long long ans = INF;
 for(int i=1; i<=k-n+1; i++){
 	long long cur = -INF;
 	for(int j=1; j<=n; j++){
 		long long temp = 0;
 		temp += 1ll * abs(orang[j]-kunci[j+i-1]);
 		temp += 1ll * abs(kunci[j+i-1]-p);
 		cur = max(cur, temp);
 	}
 	ans = min(ans, cur);
 }

 cout << ans;

}
