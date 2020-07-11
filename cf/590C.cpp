#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const int MAX = 1e9;

vector<pair<int, int>> pos[4];
int D[4];
int n, m;
int ans = MAX;

bool isState(char c) {
  int t = c - '0';
  return (t >= 1 && t <= 3);
}

bool valid(int a, int b) {
  if(a < 0 || a >= n) return false;
  if(b < 0 || b >= m) return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  vector<vector<char>> ve(n, vector<char>(m));
  vector<vector<int>> dis[4];
  for(int i = 1; i <= 3; i++)
    dis[i].assign(n, vector<int>(m, MAX));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> ve[i][j];
      if(isState(ve[i][j])) {
        pos[ve[i][j] - '0'].emplace_back(i,j);
      }
    }
  }
  for(int i = 1; i <= 3; i++) {
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    queue<pair<int, int>> Q;
    for(auto j : pos[i]) {
      dis[i][j.first][j.second] = 0;
      vis[j.first][j.second] = true;
      Q.push(j);
    }
    while(!Q.empty()) {
      auto cur = Q.front();
      Q.pop();
      int x = cur.first, y = cur.second;
      for(int j = 0; j < 4; j++) {
        int nx = x + dx[j];
        int ny = y + dy[j];
        if(!valid(nx, ny))
          continue;
        if(vis[nx][ny])
          continue;
        if(ve[nx][ny] == '#')
          continue;
        vis[nx][ny] = true;
        dis[i][nx][ny] = dis[i][x][y] + 1;
        if(ve[nx][ny] == '.') 
          Q.emplace(nx, ny);
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(dis[1][i][j] >= MAX || dis[2][i][j] >= MAX || dis[3][i][j] >= MAX)
        continue;
      if(ve[i][j] != '.')
        continue;
      ans = min(ans, dis[1][i][j] + dis[2][i][j] + dis[3][i][j] - 2);
    }
  }
  for(int i = 1; i <= 3; i++) {
    int next = (i + 1);
    if(next > 3) next -= 3;
    int mn = MAX;
    for(auto j : pos[next]) {
      mn = min(mn, dis[i][j.first][j.second]);
    }
    D[i] = mn;
  }
  for(int i = 1; i <= 3; i++) {
    int next = (i + 1);
    if(next > 3) next -= 3;
    if(D[i] >= MAX || D[next] >= MAX)
      continue;
    ans = min(ans, D[i] + D[next] - 2);
  }
  cout << (ans >= MAX ? -1 : ans) << '\n';
  return 0;
}