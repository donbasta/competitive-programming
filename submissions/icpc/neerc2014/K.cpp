#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int tc;
	cin >> tc;
	while(tc--){

		int n;
		cin >> n;
		set<pair<int,int>> ed;
		vector<int> adj[n+1];

		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				cin >> ar[i][j];
			}
			int k = ar[i][2];
			if(!ed.count({min(i,k),max(i,k)})){
				adj[i].push_back(k);
				adj[k].push_back(i);
				ed.insert({min(i,k),max(i,k)});
			}
		}

		//find longest path
		int t1 = ar[1][n];
		int t2 = ar[t1][n];

		//find longest common subsequence of ar[t1] and ar[t2]
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(ar[t1][i] == ar)
			}
		}

	}

}
