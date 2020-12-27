#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e5+69;

int n,k;
int pre[N], ar[N];
int mn = 2e9+69;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for(int i=1; i<=n; i++){
		int x;
		cin >> x;
		ar[i] = x;
		pre[i] = pre[i-1] + x;
		mn = min(x, mn);
	}

	int last = pre[k-1] - pre[0];
	for(int i=k; i<=n; i++){
		if(last + ar[i] < 0){
			last = last + ar[i] - ar[i-k+1];
			continue;
		}
		ar[i] -= need;
			

	}

}