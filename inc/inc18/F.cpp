#include <bits/stdc++.h>
using namespace std;

vector<int> ve[26];
int n, q;

struct FlowEdge {
  int v, u;
  long long cap, flow = 0;
  FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
  const long long flow_inf = 1e18;
  vector<FlowEdge> edges;
  vector<vector<int>> adj;
  int n, m = 0;
  int s, t;
  vector<int> level, ptr;
  queue<int> q;

  Dinic(int n, int s, int t) : n(n), s(s), t(t) {
	  adj.resize(n);
	  level.resize(n);
	  ptr.resize(n);
  }

  void add_edge(int v, int u, long long cap) {
    edges.emplace_back(v, u, cap);
    edges.emplace_back(u, v, 0);
    adj[v].push_back(m);
    adj[u].push_back(m + 1);
    m += 2;
  }

  bool bfs() {
	  while (!q.empty()) {
	    int v = q.front();
	    q.pop();
	    for (int id : adj[v]) {
	      if (edges[id].cap - edges[id].flow < 1)
	          continue;
	      if (level[edges[id].u] != -1)
	          continue;
	      level[edges[id].u] = level[v] + 1;
	      q.push(edges[id].u);
	    }
	  }
	  return level[t] != -1;
  }

  long long dfs(int v, long long pushed) {
	  if (pushed == 0)
	  	return 0;
	  if (v == t)
	  	return pushed;
	  for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
      int id = adj[v][cid];
      int u = edges[id].u;
      if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
      	continue;
      long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
      if (tr == 0)
      	continue;
      edges[id].flow += tr;
      edges[id ^ 1].flow -= tr;
      return tr;
	  }
	  return 0;
  }

  long long flow() {
	  long long f = 0;
	  while (true) {
      fill(level.begin(), level.end(), -1);
      level[s] = 0;
      q.push(s);
      if (!bfs())
          break;
      fill(ptr.begin(), ptr.end(), 0);
      while (long long pushed = dfs(s, flow_inf)) {
          f += pushed;
      }
	  }
	  return f;
  }
};

bool capp(char c) {
	return (c >= 'A') && (c <= 'Z');
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> q;
	cin.ignore();
	for(int i = 1; i <= n; i++) {
		string s;
		getline(cin, s);
		vector<bool> udah(26, 0);
		for(auto j : s) {
			if(capp(j)){
				if(!udah[j - 'A']){
					ve[j - 'A'].push_back(i);
					udah[j - 'A'] = true;
				}
			}
		}
	} 
	
	for(int i = 0; i < 26; i++) {
		assert((int)ve[i].size() <= n);
	}

	while(q--) {
		string s;
		cin >> s;
		int sz = (int) s.length();

		if(sz > n) {
			cout << "NO" << "\n";
			continue;
		}

		Dinic din = Dinic(n + sz + 2, 0, n + sz + 1);

		for(int i = 0; i < sz; i++) {
			for(auto j : ve[s[i] - 'A']){
				din.add_edge(n + i + 1, j, 1);
			}
			din.add_edge(0, n + i + 1, 1);
		}
		for(int i = 1; i <= n; i++) {
			din.add_edge(i, n + sz + 1, 1);
		}

		int lol = din.flow();
		cout << (lol >= sz ? "YES" : "NO");
		cout << "\n";
	}

	return 0;
}
