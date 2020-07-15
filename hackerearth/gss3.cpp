#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

const int MAXN = 5e4+1;

LL seg[4*MAXN], sum[4*MAXN];
LL pre[4*MAXN], post[4*MAXN];
LL arr[MAXN];

void build(int v, int l, int r){
	if(l==r){
		sum[v] = arr[l];
		seg[v] = arr[l];
		post[v] = arr[l];
		pre[v] = arr[l];
	} else {
		build(v<<1, l, (l+r)>>1);
		build((v<<1)+1, ((l+r)>>1)+1, r);
		seg[v] = max(seg[v<<1], seg[(v<<1)+1]);
		seg[v] = max(seg[v], post[v<<1]+pre[(v<<1)+1]);
		sum[v] = sum[v<<1] + sum[(v<<1)+1];
		pre[v] = max(pre[v<<1], pre[(v<<1)+1]+sum[v<<1]);
		post[v] = max(post[(v<<1)+1], post[v<<1]+sum[(v<<1)+1]);
	}
}

void upd(int v, int l, int r, int tar){
	if(l==r){
		sum[v] = arr[l];
		seg[v] = arr[l];
		post[v] = arr[l];
		pre[v] = arr[l];
	} else {
		int m = (l+r)>>1;
		if(tar<=m) upd(v<<1, l, m, tar);
		else upd((v<<1)+1, m+1, r, tar);
		seg[v] = max(seg[v<<1], seg[(v<<1)+1]);
		seg[v] = max(seg[v], post[v<<1]+pre[(v<<1)+1]);
		sum[v] = sum[v<<1] + sum[(v<<1)+1];
		pre[v] = max(pre[v<<1], pre[(v<<1)+1]+sum[v<<1]);
		post[v] = max(post[(v<<1)+1], post[v<<1]+sum[(v<<1)+1]);
	}
}

LL que1(int v, int l, int r, int q){
	if(l==r) return max(1ll*0, arr[v]);
	else {
		int m = (l+r)>>1;
		if(q<=m){
			return max(que1((v<<1)+1,m+1,r,m+1),sum[(v<<1)+1]+que1(v<<1,l,m,q));
		} else {
			return que1((v<<1)+1,m+1,r,q);
		}
	}
}

LL que2(int v, int l, int r, int q){
	if(l==r) return max(1ll*0, arr[v]);
	else {
		int m = (l+r)>>1;
		if(q>m){
			return max(que2(v<<1,l,m,m),sum[v<<1]+que2((v<<1)+1,m+1,r,q));
		} else {
			return que2(v<<1,l,m,q);
		}
	}
}

LL que(int v, int l, int r, int ql, int qr){
	if(qr<ql) return 0;
	if(l==ql && r==qr) return seg[v];
	else {
		int m = (l+r)>>1;
		if(qr<=m) return que(v<<1, l, m, ql, min(m,qr));
		else if(ql>m) return que((v<<1)+1, m+1, r, max(ql,m+1), qr);
		else {
			LL a = que(v<<2, l, m, ql, m);
			LL b = que((v<<2)+1, m+1, r, m+1, qr);
			LL ans = max(a,b);
			ans = max(ans,que1(v<<1,l,m,ql)+que2((v<<1)+1,m+1,r,qr));
			return ans;
		}
	}
}

int main(){

	int N;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> arr[i];
	}

	build(1,0,N-1);

	int M;
	cin >> M;
	while(M--){
		int q,x,y;
		cin >> q;
		if(q&1){
			cin >> x >> y;
			cout << que(1,0,N-1,x-1,y-1) << "\n";
		} else {
			cin >> x >> y;
			arr[x-1] = y;
			upd(1,0,N-1,x-1);
		}
	}

}