#include <bits/stdc++.h>
using namespace std;
 
const int N = 3e5 + 69;
const int INF = 1e9;
 
vector<int> seg[4 * N], ri;
map<pair<int, int>, int> lol;
int n, pre[N];
 
int sgn(int x){
	if(x == 0) return 0;
	return x / abs(x);
}
 
void build(int v, int tl, int tr){
	if(tl == tr){
		seg[v] = vector<int>(1, ri[tl]);
		return;
	}
	int tm = (tl + tr)/2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	merge(seg[v * 2].begin(), seg[v * 2].end(), seg[v * 2 + 1].begin(), seg[v * 2 + 1].end(), back_inserter(seg[v]));
}
 
int que(int v, int tl, int tr, int l, int r, int val){
	if(l > r || l > tr || r < tl)
		return 0;
	if(l <= tl && r >= tr){
		int pos = lower_bound(seg[v].begin(), seg[v].end(), val) - seg[v].begin();
		return (int)seg[v].size() - pos;
	}
	int tm = (tl + tr) / 2;
	return que(v * 2, tl, tm, l, r, val) + que(v * 2 + 1, tm + 1, tr, l, r, val);
}
 
pair<int,int> make_vector(pair<int,int> a, pair<int,int> b){
	int dx = b.first - a.first;
	int dy = b.second - a.second;
	if(dx == 0){
		return make_pair(0, sgn(dy));
	} else if(dy == 0){
		return make_pair(sgn(dx), 0);
	} else {
		int gcd = __gcd(abs(dx),abs(dy));
		return make_pair(dx/gcd, dy/gcd);
	}
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
 
	cin >> n;
	set<pair<int, int>> vecs;
	vector<int> all;
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		pre[i] = pre[i - 1] + k;
		vector<pair<int,int>> ve(k);
		for(int j = 0; j < k; j++){
			int x, y;
			cin >> x >> y;
			ve[j] = make_pair(x,y);
		}
		for(int j = 0; j < k; j++){
			int nx = (j == k - 1 ? 0 : j + 1);
			pair<int,int> vec = make_vector(ve[j], ve[nx]);
			if(!vecs.count(vec)) {
				lol[vec] = (int)vecs.size();
				vecs.insert(vec);
			}
			all.push_back(lol[vec]);
		}
	}
	// for(auto i : all) {
	// 	cout << i << ' ';
	// }
	int tot = (int)all.size();
	vector<int> cur(tot, INF);
	ri.resize(tot);
	for(int i = tot - 1; i >= 0; i--) {
		ri[i] = cur[all[i]];
		cur[all[i]] = i;
	}
	// cout << '\n';
	// for(auto i : ri) {
	// 	cout << i << ' ';
	// }
	// cout << '\n';
 
	build(1, 0, tot - 1);
 
	int q;
	cin >> q;
	while(q--){
		int l, r;
		cin >> l >> r;
		int b1 = pre[l - 1], b2 = pre[r];
		// cout << b1 << ' ' << b2 - 1 << " :D\n";
		cout << que(1, 0, tot - 1, b1, b2 - 1, b2) << "\n";
	}
	return 0;
}