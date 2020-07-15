#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;

struct node {
	int pre, suf, ans, sum;
	node() {pre = suf = ans = sum = 0;}
	node(int a) {pre = suf = ans = sum = a;}
	node(int a, int b, int c, int d) {pre = a; suf = b; ans = c; sum = d;}
};

int n;
vector<node> seg;
vector<int> arr;

node merge(node x, node y){
	node a = node();
	a.pre = max(x.pre, x.sum + y.pre);
	a.suf = max(y.suf, y.sum + x.suf);
	a.sum = x.sum + y.sum;
	a.ans = max(x.ans, max(y.ans, x.suf+y.pre));
	return a;
}

void build(int v, int tl, int tr){
	if(tl==tr) seg[v] = node(arr[tl]);
	else {
		int tm = (tl+tr)/2;
		build(v*2, tl, tm);
		build(v*2+1, tm+1, tr);
		seg[v] = merge(seg[v*2],seg[v*2+1]);
	}
}

void upd(int v, int tl, int tr, int pos, int val){
	if(tl==tr) seg[v] = node(val);
	else {
		int tm = (tl+tr)/2;
		if(pos<=tm) upd(v*2, tl, tm, pos, val);
		else upd(v*2+1, tm+1, tr, pos, val);
		seg[v] = merge(seg[v*2],seg[v*2+1]);
	}
}

node que(int v, int tl, int tr, int l, int r){
	if(l>r) return node(-INF,-INF,-INF,0);
	else if(l==tl && r==tr) return seg[v];
	else{
		int tm = (tl+tr)/2;
		return merge(que(v*2, tl, tm, l, min(tm,r)),que(v*2+1, tm+1, tr, max(l,tm+1), r));
	}
}

int main(){
 ios_base::sync_with_stdio(0);
 cin.tie(0), cout.tie(0);

 int tc;
 cin >> tc;
 while(tc--){

 	cin >> n;
 	arr.clear(); seg.clear();
 	arr.resize(n+5);
 	seg.resize(4*n+5);
 	for(int i=0; i<n; i++){
 		cin >> arr[i];
 	}
 	build(1,0,n-1);

 	int m;
 	cin >> m;
 	while(m--){
 		int a,b,c,d;
 		cin >> a >> b >> c >> d;
 		if(b==c){
 			cout << que(1,0,n-1,a-1,b-1).suf + que(1,0,n-1,c-1,d-1).pre - arr[b-1] << "\n";
 		} else if(b<c){
 			int aa = ((b-1<a-1) ? 0 : que(1,0,n-1,a-1,b-1).suf);
 			int bb = ((d-1<c-1) ? 0 : que(1,0,n-1,c-1,d-1).pre);
 			int mid = ((c-2<b) ? 0 : que(1,0,n-1,b,c-2).sum);
 			cout << aa + mid + bb << "\n";
 		} else {
 			node mid = que(1,0,n-1,c-1,b-1);
 			int ma = mid.ans;
 			int mb = mid.sum;
 			int mc = mid.pre;
 			int md = mid.suf;
 			int kiri = ((c-2<a-1) ? 0 : que(1,0,n-1,a-1,c-2).suf);
 			int kanan = ((d-1<b) ? 0 : que(1,0,n-1,b,d-1).pre);
 			cout << max(ma, max(kiri+kanan+mb, max(mc+kiri, md+kanan))) << "\n";
 		}
 	}
 }
}