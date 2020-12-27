/*
ID: faddila1
TASK: castle
LANG: C++14                 
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 50;

int M,N;
bool vis[MAX+5][MAX+5];
int bor[MAX+5][MAX+5];
int par[MAX+5][MAX+5];
int sz[2505];

void dfs(int a, int b, int pos){

	if(a<1 || a>N || b<1 || b>M) {return;}
	if(vis[a][b]) return;

	vis[a][b] = true;
	par[a][b] = pos;
	sz[pos]++;
	if(!(bor[a][b]&1)) dfs(a,b-1,pos);
	if(!((bor[a][b]>>1)&1)) dfs(a-1,b,pos);
	if(!((bor[a][b]>>2)&1)) dfs(a,b+1,pos);
	if(!((bor[a][b]>>3)&1)) dfs(a+1,b,pos);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ofstream fout ("castle.out");
	ifstream fin ("castle.in");

	fin >> M >> N;

	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			fin >> bor[i][j];
		}
	}

	int cur = 0;
	int maks = 0;

	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			if(!vis[i][j]) {
				cur++;
				dfs(i,j,cur);
				maks = max(maks, sz[cur]);
			}
		}
	}

	int ans1 = 0, ans2 = 0;
	tuple<int,int,char> loc1, loc2;

	for(int j=M; j>=1; j--){
		for(int i=2; i<=N; i++){
			if((bor[i][j]>>1)&1){
				if(par[i-1][j]!=par[i][j] && sz[par[i-1][j]]+sz[par[i][j]] >= ans1){
					loc1 = {i,j,'N'};
					ans1 = sz[par[i-1][j]]+sz[par[i][j]];
				}
			}
		}
	}

	for(int j=M-1; j>=1; j--){
		for(int i=1; i<=N; i++){
			if((bor[i][j]>>2)&1){
				if(par[i][j]!=par[i][j+1] && sz[par[i][j]]+sz[par[i][j+1]] >= ans2){
					loc2 = {i,j,'E'};
					ans2 = sz[par[i][j]]+sz[par[i][j+1]];
				}
			}
		}
	}

	int ans;
	tuple<int,int,char> loc;

	if(ans1 > ans2){
		ans = ans1;
		loc = loc1;
	} else if(ans1 < ans2){
		ans = ans2;
		loc = loc2;
	} else {
		if(get<1>(loc1) < get<1>(loc2)){
			ans = ans1;
			loc = loc1;
		} else if(get<1>(loc1) > get<1>(loc2)){
			ans = ans2;
			loc = loc2;
		} else {
			if(get<0>(loc1) > get<0>(loc2)){
				ans = ans1;
				loc = loc1;
			} else if(get<0>(loc1) < get<0>(loc2)){
				ans = ans2;
				loc = loc2;
			} else {
				ans = ans1;
				loc = loc1;
			}
		}
	}

	fout << cur << "\n";
	fout << maks << "\n";
	fout << ans << "\n";
	fout << get<0>(loc) << " " << get<1>(loc) << " " << get<2>(loc) << "\n";

	return 0;

}
