#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2000;

int n;
bool ok = 1;
string s[N], sn[N], bar;
vector<int> adj[2 * N];
int val[2 * N];
int val_edge[2 * N][2 * N];
bool vis[2 * N];

void dfs(int v) {
  vis[v] = 1;
  for(auto ch : adj[v]) {
    if(val[ch] != -1 && val_edge[v][ch] != -1) {
      if(val_edge[v][ch] != (val[v] ^ val[ch])) {
        ok = 0; return;
      }
    }
    if(val[ch] == -1 && val_edge[v][ch] != -1) {
      val[ch] = val[v] ^ val_edge[v][ch];
    }
    if(vis[ch]) continue;
    dfs(ch);
  }
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) { cin >> s[i]; }
  for(int i = 0; i < n; i++) { cin >> sn[i]; }
  cin >> bar;
  for(int i = 0; i < 2 * n; i++) { val[i] = -1; }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      int ki = bar[i] - '0', kj = bar[j] - '0';
      int dif = (s[i][j] == sn[i][j] ? 0 : 1);
      // cerr << i << ' ' << j << ' ' << ki << ' ' << kj << ' ' << dif << '\n';
      val_edge[i][j + n] = val_edge[j + n][i] = -1;
      if(ki == 0 && kj == 0) {
        if(dif == 0) continue;
        else if(dif == 1) {
          cout << -1 << '\n';
          return;
        }
      } else if(ki == 0 && kj == 1) {
        val[i] = dif;
      } else if(ki == 1 && kj == 0) {
        val[j + n] = dif;
      } else if(ki == 1 && kj == 1){
        adj[i].push_back(j + n);
        adj[j + n].push_back(i);
        val_edge[i][j + n] = dif;
        val_edge[j + n][i] = dif;
      }
    }
  }
  // for(int i = 0; i < 2 * n; i++) { cerr << i << val[i] << '\n'; }
  for(int i = 0; i < 2 * n; i++) {
    if(!vis[i]) {
      if(val[i] != -1) {
        dfs(i);
        if(!ok) {
          cout << -1 << '\n';
          return;
        }
      } else {
        int tmp_val[2 * n];
        bool tmp_vis[2 * n];
        for(int k = 0; k < 2 * n; k++) { tmp_val[k] = val[k]; }
        for(int k = 0; k < 2 * n; k++) { tmp_vis[k] = vis[k]; }  
        int err = 0;
        for(int j = 0; j < 2; j++) {
          val[i] = j;
          dfs(i);
          if(ok) break;
          ok = 1;
          if(j == 0) {
            for(int k = 0; k < 2 * n; k++) { val[k] = tmp_val[k]; }
            for(int k = 0; k < 2 * n; k++) { vis[k] = tmp_vis[k]; }    
          }
          err++;
        }
        if(err == 2) {
          cout << -1 << '\n';
          return;
        }
      }
    }
  }
  int cnt = 0;
  for(int i = 0; i < 2 * n; i++) { 
    // cerr << i << ' ' << val[i] << '\n';
    cnt += (val[i] == 1); 
  }
  cout << cnt << '\n';
  for(int i = 0; i < 2 * n; i++) {
    if(val[i] == 1) {
      if(i < n) { cout << "row " << i; }
      else { cout << "col " << i - n; }
      cout << '\n';
    }
  }
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