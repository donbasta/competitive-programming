#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

vector<int> adj[30];
vector<int> topo;
bool vis[30];
int to[30], from[30];

void dfs(int v) {
  vis[v] = 1;
  for(auto ch : adj[v]) {
    if(vis[ch]) continue;
    dfs(ch);
  }
  topo.push_back(v);
}

void solve() {
  string s;
  vector<string> ve;

  while(cin >> s) {
    if(s == "#") break;
    ve.push_back(s);
  }

  for(int i = 0; i < (int)ve.size() - 1; i++) {
    int j = 0;
    int mn = min((int)ve[i].length(), (int)ve[i + 1].length());
    while(j < mn) {
      if(ve[i][j] == ve[i + 1][j]) { j++; continue; }
      adj[ve[i][j] - 'A'].push_back(ve[i + 1][j] - 'A');
      to[ve[i + 1][j] - 'A']++;
      from[ve[i][j] - 'A']++;
      break;
    }
  }

  for(int i = 0; i < 26; i++) {
    // cerr << (int)adj[i].size() << ' ' << (char)(i + 'A') << '\n';
    if(to[i] > 0 || from[i] == 0) continue;
    dfs(i);
    for(int j = (int)topo.size() - 1; j >= 0; j--) {
      cout << (char) (topo[j] + 'A');
    }
    topo.clear();
  }

  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}