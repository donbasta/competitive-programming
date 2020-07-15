/*
ID: faddila1
TASK: hamming
LANG: C++14                 
*/
#include <bits/stdc++.h>
using namespace std;

int n,b,d;
vector<int> cur;

int hamming(int x, int y){
	int ans = 0;
	for(int i=0; i<b; i++){
		if(((x>>i)&1) != ((y>>i)&1)) ans++;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ofstream fout ("hamming.out");
	ifstream fin ("hamming.in");

	fin >> n >> b >> d;

	for(int i=0; i<(1<<b); i++){
		bool ok = true;
		for(auto j : cur){
			if(hamming(i,j)<d) ok = false;
		}
		if(ok) cur.push_back(i);
		if((int)cur.size()==n) break;
	}

	for(int i=0; i<n; i++){
		fout << cur[i] << ((i==n-1 || i%10==9) ? "\n" : " ");
	}

}
