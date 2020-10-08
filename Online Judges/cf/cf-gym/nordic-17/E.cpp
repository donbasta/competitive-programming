#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 5e2;

int h, w;
ll ans = 0;
int dep[N + 5][N + 5], mx[N + 5][N + 5];
bool vis[N + 5][N + 5];

const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool valid(int x, int y) {
  return (x >= 0 && x < h && y >= 0 && y < w);
}

void ff(int x, int y) {
  priority_queue<pair<int, pair<int, int>>> Q;
  vis[x][y] = true;
  mx[x][y] = -dep[x][y];
  ans += mx[x][y];
  Q.emplace(mx[x][y], make_pair(x, y));
  // cerr << ans << ":D";
  while(!Q.empty()) {
    auto now = Q.top();
    int MX = now.first;
    int xx = now.second.first, yy = now.second.second;
    Q.pop();
    for(int i = 0; i < 8; i++) {
      int nx = xx + dx[i];
      int ny = yy + dy[i];
      if(!valid(nx, ny)) continue;
      if(vis[nx][ny]) continue;
      if(dep[nx][ny] >= 0) continue;
      mx[nx][ny] = min(-dep[nx][ny], MX);
      ans = ans + mx[nx][ny];
      vis[nx][ny] = true;
      Q.emplace(mx[nx][ny], make_pair(nx, ny));
    }
  }
}

void solve() {
  cin >> h >> w;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      cin >> dep[i][j];
    }
  }
  int sx, sy;
  cin >> sx >> sy;
  sx--, sy--;
  ff(sx, sy);
  cout << ans << '\n';
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