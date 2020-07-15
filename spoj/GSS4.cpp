#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;

struct node{
	bool tag;
	long long sum;
	node() {sum = 0; tag = false;}
	node(long long val, bool stat) {sum = val; tag = stat;}
	node(const node& a) {tag = a.tag; sum = a.sum;}
};

long long arr[maxn+1];
node seg[4*maxn+1];

node merge(node a, node b){
	return node(a.sum+b.sum, a.tag&&b.tag);
}

void build(int v, int tl, int tr){
	if(tl==tr) {seg[v].sum = arr[tl]; seg[v].tag = false;}
	else {
		int tm = (tl+tr)/2;
		build(v*2, tl, tm);
		build(v*2+1, tm+1, tr);
		seg[v] = merge(seg[v*2],seg[v*2+1]);
	}
}

void upd(int v, int tl, int tr, int l, int r){
	if(seg[v].tag) return ;
	if(l>r) return;
	if(tl == tr) {
		arr[tl] = sqrt(arr[tl]);
		seg[v].sum = arr[tl];
		if(arr[tl]==1) seg[v].tag = true;
	} else {
		int tm = (tl+tr)/2;
		upd(v*2, tl, tm, l, min(r,tm));
		upd(v*2+1, tm+1, tr, max(l,tm+1), r);
		seg[v] = merge(seg[v*2], seg[v*2+1]);
	}
}

long long query(int v, int tl, int tr, int l, int r){
	if(l>r) return 0;
	if(l==tl && r==tr) return seg[v].sum;
	else {
		int tm = (tl+tr)/2;
		return query(v*2,tl,tm,l,min(r,tm))+query(v*2+1,tm+1,tr,max(l,tm+1),r);
	} 
}

int main(){

 int n,m;
 int idx = 1;

 while(fscanf(stdin, "%d", &n)){
 	// arr.clear(); seg.clear();
 	// arr.resize(n+5); seg.resize(4*n+5);

 	for(int i=0; i<n; i++){
 		scanf("%lld", &arr[i]);
 	}
 	build(1,0,n-1);

 	scanf("%d", &m);
 	printf("Case #%d:\n", idx);
 	while(m--){
 		int qu,x,y;
 		scanf("%d %d %d", &qu, &x, &y);
 		if(x>y) swap(x,y);
 		if(qu==0){
 			upd(1,0,n-1,x-1,y-1);
 		} else {
 			printf("%lld\n", query(1,0,n-1,x-1,y-1));
 		}
 	}
 }
 printf("\n");
}