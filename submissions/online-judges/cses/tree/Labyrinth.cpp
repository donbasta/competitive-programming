#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e3;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

bool vis[N + 5][N + 5];
int n, m;
char c[N + 5][N + 5];
pair<int, int> start, endz, par[N + 5][N + 5];

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
      if(c[nx][ny] == '#') continue;
      if(vis[nx][ny]) continue;
      par[nx][ny] = make_pair(x, y);
      vis[nx][ny] = true;
      Q.emplace(nx, ny);
    }
  }
}

string generatePath(pair<int, int> S, pair<int, int> E) {
  if(S == E) return "";
  pair<int, int> prev = par[E.first][E.second];
  string ret = generatePath(S, prev);
  if(prev.first - E.first == 1) ret += 'U';
  else if(prev.first - E.first == -1) ret += 'D';
  else if(prev.second - E.second == 1) ret += 'L';
  else if(prev.second - E.second == -1) ret += 'R';
  return ret;
}

void solve() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> c[i][j];
      if(c[i][j] == 'A') start = make_pair(i, j);
      if(c[i][j] == 'B') endz = make_pair(i, j);
    }
  }
  ff(start.first, start.second);
  if(!vis[endz.first][endz.second]) {
    cout << "NO";
  } else {
    cout << "YES" << '\n';
    string ans = generatePath(start, endz);
    cout << (int)ans.length() << '\n';
    cout << ans;
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