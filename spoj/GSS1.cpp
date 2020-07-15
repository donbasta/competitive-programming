#include <bits/stdc++.h>

#define mid ((l+r)>>1)

using namespace std;

const int MAXN = 5e4+5;

struct node {

	int ans, sum, pref, suf;
	node() { ans = sum = pref = suf = 0; }
	node(int val){
		ans = sum = pref = suf = val;
	}
	void merge(const node & n1, const node & n2){
		ans = max(n1.ans, n2.ans);
		ans = max(ans, n1.suf+n2.pref);
		sum = n1.sum + n2.sum;
		pref = max(n1.pref, n1.sum+n2.pref);
		suf = max(n2.suf, n2.sum+n1.pref);
	}

} ;

node seg[4*MAXN];
node arr[MAXN];
int N,M,x,y;


void build(int v, int l, int r){
	if (l==r){
		seg[v] = arr[l];
	} else {
		build(v<<1, l, mid);
		build((v<<1)+1, mid+1, r);
		seg[v].merge(seg[v<<1],seg[(v<<1)+1]);
	}
}

node que(int v, int l, int r, int ql, int qr){
	if(l==ql && r==qr){
		return seg[v];
	} else {
		if(qr<=mid) return que(v<<1, l, mid, ql, qr);
		else if(ql>mid) return que((v<<1)+1, mid+1, r, ql, qr);
		else {
			node left = que(v<<1, l, mid, ql, mid);
			node right = que((v<<1)+1, mid+1, r, mid+1, qr);
			node t = node();
			t.merge(left, right);
			return t;
		}
	}
}

int main(){

	cin >> N;
	for(int i=0; i<N; i++){
		cin >> x;
		arr[i] = node(x);
	}

	build(1,0,N-1);

	cin >> M;
	while(M--){
		cin >> x >> y;
		cout << que(1,0,N-1,x-1,y-1).ans << '\n';
	}


}