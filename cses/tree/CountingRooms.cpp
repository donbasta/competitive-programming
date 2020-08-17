#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int N = 1e3;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
 
bool vis[N + 5][N + 5];
int n, m;
string s[N + 5];
 
bool valid(int a, int b) {
  return (a >= 0 && a < n && b >= 0 && b < m);
}
 
void ff(int a, int b) {
  vis[a][b] = true;
  queue<pair<int, int>> Q;
  Q.emplace(a, b);
  while(!Q.empty()) {
    auto cur = Q.front();
    int x = cur.first, y = cur.second;
    Q.pop();
    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(!valid(nx, ny)) continue;
      if(s[nx][ny] == '#') continue;
      if(vis[nx][ny]) continue;
      vis[nx][ny] = true;
      Q.emplace(nx, ny);
    }
  }
}
 
void solve() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int room = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(s[i][j] == '#') continue;
      if(!vis[i][j]) {
        room++;
        ff(i, j);
      }
    }
  }
  cout << room << '\n';
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