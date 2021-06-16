#include <bits/stdc++.h>
using namespace std;

int m,n;
vector<int> par;
vector<long long> arr, bit;

int fpar(int a){
	return (a==par[a] ? a : par[a] = fpar(par[a]));
}

void upd(int a, int val){
	for(;a<n;a+=a&-a){
		bit[a] += val;
	}
}

void change(int a, int b){
	for(;a<=b;a=fpar(a+1)){
		upd(a,-arr[a]);
		arr[a] = sqrt(arr[a]);
		upd(a,arr[a]);
		if(arr[a] == 1 && a<n-1) par[a] = fpar(a+1);
	}
}

long long get(int a){
	long long res = 0;
	for(;a>0;a-=a&-a){
		res += bit[a];
	}
	return res;
}

long long get(int a, int b){
	return (b>0 ? get(a)-get(b-1) : get(a));
}

int main(){
	int idx = 1;
	while(fscanf(stdin, "%d", &n)){
		// par.resize(n);
		// arr.resize(n);
		// bit.clear();
		// bit.resize(n);

	 // for(int i=0; i<n; i++){
	 // 	par[i] = i;
	 // 	scanf("%lld", &arr[i]);
	 // 	upd(i,arr[i]);
	 // }

	 // scanf("%d", &m);
	 // printf("Case #%d:\n", idx);
	 // while(m--){
	 // 	int qu,x,y;
	 // 	scanf("%d %d %d", &qu, &x, &y);
	 // 	if(x>y) swap(x,y);
	 // 	if(qu==0){
	 // 		upd(x-1,y-1);
	 // 	} else {
	 // 		printf("%lld\n", get(x-1,y-1));
	 // 	}
	 // }
	 // idx++;
	 // printf("\n");
	}
}