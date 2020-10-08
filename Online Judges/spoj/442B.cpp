#include <bits/stdc++.h>

using namespace std;

int n;
vector<double> q;
double x, ans;
double prod, cur;

int main(){

	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> x;
		q.push_back(1-x);
	}

	sort(q.begin(),q.end());
	
	for(int i=0; i<=n; i++){
		for(int j=0; j<=n-i; j++){
			if(i+j==0) continue;
			prod=1;
			cur=0;
			for(int k=0; k<i; k++){
				cur = cur*q[k]+prod*(1-q[k]);
				prod *= q[k];
			}
			for(int k=n-1; k>n-1-j; k--){
				cur = cur*q[k]+prod*(1-q[k]);
				prod *= q[k];
			}
			ans = max(cur,ans);
		}
	}

	cout << fixed << setprecision(10) << ans;

}