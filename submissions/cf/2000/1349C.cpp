#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e3;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

bool ar[N + 5][N + 5], vis[N + 5][N + 5], vis2[N + 5][N + 5];
int val[N + 5][N + 5];
int n, m, t;

bool valid(int r, int c) {
  return r >= 0 && r < n && c >= 0 && c < m;
}

void ff(int r, int c) {
  queue<pair<int, int>> Q, Border;
  Q.emplace(r, c);
  vis[r][c] = 1;
  while (!Q.empty()) {
    auto now = Q.front();
    Q.pop();
    int rr = now.first, cc = now.second;
    bool ujung = false;
    for (int i = 0; i < 4; i++) {
      int nr = rr + dx[i];
      int nc = cc + dy[i];
      if (!valid(nr, nc)) continue;
      if (ar[nr][nc] != ar[rr][cc]) {
        ujung = true;
        continue;
      }
      if (vis[nr][nc]) continue;
      Q.emplace(nr, nc);
      vis[nr][nc] = 1;
    }
    if (ujung) {
      Border.emplace(rr, cc);
      vis2[rr][cc] = 1;
      // val[rr][cc] = 1;
    }
  }
  while (!Border.empty()) {
    auto now = Border.front();
    Border.pop();
    int rr = now.first, cc = now.second;
    for (int i = 0; i < 4; i++) {
      int nr = rr + dx[i];
      int nc = cc + dy[i];
      if (!valid(nr, nc)) continue;
      if (ar[nr][nc] != ar[rr][cc]) continue;
      if (vis2[nr][nc]) continue;
      vis2[nr][nc] = 1;
      val[nr][nc] = val[rr][cc] + 1;
      Border.emplace(nr, nc);
    }
  }
}

void solve() {
  cin >> n >> m >> t;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      ar[i][j] = (s[j] - '0');
      if ((i + j) & 1) ar[i][j] ^= 1;
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!vis[i][j]) {
        cnt++;
        ff(i, j);
      }
    }
  }  
  while (t--) {
    int i, j;
    long long p;
    cin >> i >> j >> p;
    --i, --j, --p;
    bool col = ar[i][j];
    if ((i + j) & 1) col ^= 1;
    if ((cnt == 1) || (n == 1 && m == 1) || (p < (long long) val[i][j])) {
      cout << col;
    } else {
      p -= val[i][j];
      cout << ((p & 1) ? col : (col ^ 1));
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