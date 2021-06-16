#include <bits/stdc++.h>
using namespace std;

int m,n;
vector<int> par;
vector<long long> arr, bit;

int fpar(int a){
	return (a==par[a] ? a : par[a] = fpar(par[a]));
}

void upd(int a, long long val){
	for(;a<=n;a+=(a&-a)){
		bit[a] += val;
	}
}

void change(int a, int b){
	for(;a<=b;a=fpar(a+1)){
		upd(a,-arr[a]);
		arr[a] = sqrt(arr[a]);
		upd(a,arr[a]);
		if(arr[a] == 1) par[a] = fpar(a+1);
	}
}

long long get(int a){
	long long res = 0;
	for(;a>0;a-=(a&-a)){
		res += bit[a];
	}
	return res;
}

long long get(int a, int b){
	return get(b)-get(a-1);
}

int main(){
	int idx = 1;
	while(scanf("%d", &n)!=EOF){
		par.resize(n+5);
		arr.resize(n+5);
		bit.clear();
		bit.resize(n+5,0);

	 for(int i=1; i<=n; i++){
	 	par[i] = i;
	 	scanf("%lld", &arr[i]);
	 	upd(i,arr[i]);
	 }
	 par[n+1] = n+1;

	 scanf("%d", &m);
	 printf("Case #%d:\n", idx);
	 while(m--){
	 	int qu,x,y;
	 	scanf("%d %d %d", &qu, &x, &y);
	 	if(x>y) swap(x,y);
	 	if(qu==0){
	 		change(x,y);
	 	} else {
	 		printf("%lld\n", get(x,y));
	 	}
	 }
	 idx++;
	 printf("\n");
	}
}