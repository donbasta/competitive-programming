#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

bool vis[N+5];
vector<int> adj[N+5];
vector<int> ans;

void dfs(int node){
	vis[node] = true;
	for(auto i : adj[node]){
		if(!vis[i]){
			dfs(i);
		}
	}
	ans.push_back(node);
}

void toposort(){
	for(int i=0; i<N; i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	reverse(ans.begin(),ans.end());
}