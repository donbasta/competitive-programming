#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int INF = 1e9 + 69;
const int N = 310;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int n, m;
int ar[N][N];

bool valid(int a, int b) {
  return a >= 1 && a <= n && b >= 1 && b <= m;
}

int f(int t) {
  vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));
  int res = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(vis[i][j] || ar[i][j] <= t)
        continue;
      queue<pair<int, int>> Q;
      Q.push(make_pair(i, j));
      vis[i][j] = true;
      while(!Q.empty()) {
        pair<int, int> cur = Q.front();
        int x = cur.first;
        int y = cur.second;
        Q.pop();
        for(int k = 0; k < 4; k++) {
          int nx = x + dx[k];
          int ny = y + dy[k];
          if(!valid(nx, ny)) continue;
          if(ar[nx][ny] <= t) continue;
          if(vis[nx][ny]) continue;
          Q.push(make_pair(nx, ny));
          vis[nx][ny] = true;
        }
      }
      res++;
    }
  }
  return res;
}

int ternary_search(int l, int r){
  while(r - l >= 10){
    // cerr << l << ' ' << r << '\n';
    int m1 = l + (r - l) / 3;
    int m2 = r - (r - l) / 3;
    int f1 = f(m1);
    int f2 = f(m2);
    if(f1 < f2){
      l = m1 + 1;
    } else {
      r = m2;
    }
  }
  int maks = 0;
  for(; l <= r ; l++){
    maks = max(maks, f(l));
  }
  return maks;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  // #ifndef ONLINE_JUDGE
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", stdout);
  // #endif

  cin >> n >> m;
  int mkx = -1;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin >> ar[i][j];
      mkx = max(mkx, ar[i][j]);
    }
  }

  int ans = f(0);
  // for(int i = 1; i <= n; i++) {
  //   for(int j = 1; j <= m; j++) {
  //     ans = max(ans, f(ar[i][j]));
  //   }
  // }

  // for(int i = 1; i <= mx; i++) {
  //   ans = max(ans, f(i));
  // }
 
  int mn = 0, mx = INF;
  ans = ternary_search(mn, mx);

  cout << ans << '\n';

  return 0;
}