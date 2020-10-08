#include <bits/stdc++.h>
#define VVI vector<vector<int> >
#define VI vector<int>

using namespace std;

VVI MAT;
VVI bit;
int N;

void upd(int a, int b, int val){
	int ch = val - MAT[a][b];
	for(int i = a; i <= N; i += i&-i){
		for(int j = b; j <= N; j += j&-j){
			bit[i][j] += ch;
		}
	}
	MAT[a][b] = val;
}

int pre(int a, int b){
	int res = 0;
	for(int i = a; i > 0; i -= i&-i){
		for(int j = b; j > 0; j -= j&-j){
			res += bit[i][j];
		}
	}
	return res;
}

int que(int a, int b, int a1, int b1){
	return (pre(a1,b1)-pre(a-1,b1)-pre(a1,b-1)+pre(a-1,b-1));
}

int main(){

	ios_base::sync_with_stdio(false); cin.tie(); cout.tie();

	int tc;
	scanf("%d", &tc);
	while(tc--){
		scanf("%d", &N);
		N++;
		MAT.resize(N+2);
		for(auto &i : MAT){
			i.resize(N+2);
			for(auto &j : i){
				j = 0;
			}
		}
		bit.resize(N+2);
		for(auto &i : bit){
			i.resize(N+2);
			for(auto &j : i){
				j = 0;
			}
		}

		string S;
		cin >> S;

		int x,y,x1,y1,num;
		while(S != "END"){
			if(S == "SET"){
				scanf("%d%d%d",&x,&y,&num);
				upd(x+1,y+1,num);
			} else if (S == "SUM"){
				scanf("%d%d%d%d", &x,&y,&x1,&y1);
				printf("%d\n",que(x+1,y+1,x1+1,y1+1));
			} 
			cin >> S;
		}

		printf("\n");

	}

}