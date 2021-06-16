#include <bits/stdc++.h>

using namespace std;

const int MAXN=2e4+5;

int bit[MAXN];
int N;
int MSB;

int find(int cum){
	int pos;
	int idx = 0;
	int bm = MSB;
	while(bm != 0){
		pos = idx + bm;
		bm >>= 1;
		if(pos > N) continue;
		if(cum >= bit[pos]){
			cum -= bit[pos];
			idx = pos;
		}
	}
	return idx;
}

int pre(int x){
	int res = 0;
	for(; x > 0; x -= x&-x){
		res += bit[x];
	}
	return res;
}

void upd(int x){
	for(; x <= N; x += x&-x){
		bit[x]--;
	}
}

int main(){
	
	int tc;
	cin >> tc;
	while(tc--){

		cin >> N;
		MSB = 1<<(int)floor(log2(N));
		int ans[N+5];
		ans[0] = 0;
		int pos[N+5];
		pos[0] = 0;
		int cur;

		for(int i=1; i<=N; i++){
			bit[i] = i&-i;
		}

		for(int i=1; i<=N; i++){
			cur = i;
			cur += pre(pos[i-1]);
			cur %= (N-i+1);
			cur++;
			pos[i] = find(cur-1)+1;
			ans[pos[i]] = i;
			upd(pos[i]);
		}

		for(int i=1; i<=N; i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
		
	}
	
}