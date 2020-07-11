#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int INF = 1e9 + 69;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int h, w, k;
int x1, y11, x2, y2;
queue<pair<int, int>> Q;

bool valid(int a, int b) {
  return a >= 1 && a <= h && b >= 1 && b <= w;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> h >> w >> k;
  cin >> x1 >> y11;
  cin >> x2 >> y2;

  vector<vector<char>> c(h + 1, vector<char>(w + 1));
  vector<vector<bool>> vis(h + 1, vector<bool>(w + 1, 0));
  vector<vector<int>> dist(h + 1, vector<int>(w + 1, INF));
  for(int i = 1; i <= h; i++) {
    for(int j = 1; j <= w; j++) {
      cin >> c[i][j];
    }
  }

  Q.emplace(x1, y11);
  dist[x1][y11] = 0;
  while(!Q.empty()) {
    pair<int, int> cur = Q.front();
    int x = cur.first;
    int y = cur.second;
    vis[x][y] = true;
    Q.pop();
    for(int i = 0; i < 4; i++) {
      for(int j = 1; j <= k; j++) {
        int nx = x + j * dx[i];
        int ny = y + j * dy[i];
        if(!valid(nx, ny) || c[nx][ny] == '@' || dist[nx][ny] <= dist[x][y]) break;
        if(dist[nx][ny] == dist[x][y] + 1) continue;
        if(vis[nx][ny]) continue;
        dist[nx][ny] = dist[x][y] + 1;
        Q.emplace(nx, ny);
      }
    }
  }
  if(!vis[x2][y2])
    cout << -1 << '\n';
  else 
    cout << dist[x2][y2] << '\n';
  return 0;
}
