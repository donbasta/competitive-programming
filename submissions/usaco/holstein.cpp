/*
ID: faddila1
TASK: holstein
LANG: C++14                 
*/
#include <bits/stdc++.h>
using namespace std;

int v;
int vt[26];
int g;
int fd[16][26];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ifstream fin ("holstein.in");
	ofstream fout ("holstein.out");

	fin >> v;
	for(int i=1; i<=v; i++){
		fin >> vt[i];
	}
	fin >> g;
	for(int i=0; i<g; i++){
		for(int j=1; j<=v; j++){
			fin >> fd[i][j];
		}
	}

	int sz = g+1;
	int ans = 0;

	for(int i=1; i<(1<<g); i++){
		int tot[v+1];
		bool ok = true;
		memset(tot, 0, sizeof(tot));
		for(int j=0; j<g; j++){
			if((i>>j)&1){
				for(int k=1; k<=v; k++) tot[k] += fd[j][k];
			}
		}
		for(int j=1; j<=v; j++){
			if(tot[j]<vt[j]) ok = false;
		}
		if(ok){
			int bit = __builtin_popcount(i);
			if(bit<sz){
				sz = bit;
				ans = i;
			}
		}
	}

	fout << sz << " ";

	int cnt = 1;
	vector<int> idx;
	while(ans > 0) {
		if(ans&1) idx.push_back(cnt);
		cnt++;
		ans >>= 1;
	}

	for(int i=0; i<(int)idx.size(); i++){
		fout << idx[i];
		if(i<(int)idx.size()-1) fout << " ";
	}


	fout << "\n";

}
