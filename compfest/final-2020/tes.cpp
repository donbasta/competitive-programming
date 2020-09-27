#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int dx[] = {1, -1, 1, -1, 2, -2, 2, -2};
int dy[] = {2, 2, -2, -2, 1, 1, -1, -1};
int INF = 1e9;

const int N = 1000;
bool vis[N + 5][N + 5];
int val[N + 5][N + 5];

void solve() {
  int n, m;
  cin >> n >> m;
  queue<pair<int, int>> q;
  q.emplace(1, 1);
  vis[1][1] = 1;
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    int x = cur.first, y = cur.second;
    for(int i = 0; i < 8; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
      if(vis[nx][ny]) continue;
      vis[nx][ny] = 1;
      val[nx][ny] = val[x][y] + 1;
      q.emplace(nx, ny);
    }
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(!vis[i][j]) cout << INF << ' ';
      else cout << val[i][j] << ' ';
    }
    cout << '\n';
  }

  cout << "-------------\n";

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      // if(i < 3 || j < 3)
      if((i + j) % 3 == 1)
        cout << val[i][j] - (i + j) / 3 << " ";
      else cout << "  ";
    }
    cout << '\n';
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