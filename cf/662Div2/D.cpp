#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2000;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m;
ll Ans;
string s[N];
int val[N][N];
bool vis[N][N];
bool vis2[N][N];
bool bor[N][N];

bool valid(int r, int c) {
  return (r >= 0 && r < n && c >= 0 && c < m);
}

bool border(int r, int c) {
  return (r == 0 || r == n - 1 || c == 0 || c == m - 1);
}

void ff(int r, int c) {
  ll ans = 0;
  char C = s[r][c];
  queue<pair<int, int>> Q, Border;
  vis[r][c] = true;
  Q.emplace(r, c);
  while(!Q.empty()) {
    bool isBorder = false, ok = true;
    auto now = Q.front();
    Q.pop();
    int rr = now.first;
    int cc = now.second;
    if(border(rr, cc)) isBorder = true;
    for(int i = 0; i < 4; i++) {
      int nr = rr + dx[i];
      int nc = cc + dy[i];
      if(!valid(nr, nc)) continue;
      ok &= (s[nr][nc] == C);
      if(vis[nr][nc] || s[nr][nc] != C) continue;
      vis[nr][nc] = true;
      Q.emplace(nr, nc);
    }
    if(!ok) isBorder = true;
    if(isBorder) {
      vis2[rr][cc] = true;
      Border.emplace(rr, cc);
      val[rr][cc] = 1;
    }
  }
  ans = Border.size();
  while(!Border.empty()) {
    auto now = Border.front();
    Border.pop();
    int rr = now.first;
    int cc = now.second;
    for(int i = 0; i < 4; i++) {
      int nr = rr + dx[i];
      int nc = cc + dy[i];
      if(!valid(nr, nc)) continue;
      if(vis2[nr][nc]) continue;
      if(s[nr][nc] != C) continue;
      vis2[nr][nc] = true;
      val[nr][nc] = val[rr][cc] + 1;
      ans += val[nr][nc];
      Border.emplace(nr, nc);
    }
  }
  Ans += ans;
}

void solve() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(!vis[i][j]) {
        ff(i, j);
      }
    }
  }
  cout << Ans << '\n';
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