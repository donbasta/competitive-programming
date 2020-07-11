#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int m, n, ok, cnt;
char ar[60][60];
bool vis[60][60];


bool valid(int x, int y) {
  return (x >= 1 && x <= n && y >= 1 && y <= m);
}

bool nb(int r, int c) {
  bool ya = false;
  for(int i = 0; i < 4; i++) {
    int rn = r + dx[i];
    int cn = c + dy[i];
    if(!valid(rn, cn))
      continue;
    ya |= (ar[rn][cn] == 'B');
  }
  return ya;
}

void ff(int r, int c) {
  vis[r][c] = true;
  if(ar[r][c] == 'G')
    ok++;
  for(int i = 0; i < 4; i++) {
    int rn = r + dx[i];
    int cn = c + dy[i];
    if(!valid(rn, cn))
      continue;
    if(ar[rn][cn] == '#' || ar[rn][cn] == 'B' || nb(rn, cn))
      continue;
    if(!vis[rn][cn])
      ff(rn, cn);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc;
  cin >> tc;
  while(tc--) {
    cin >> n >> m;
    cnt = 0;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        cin >> ar[i][j];
        if(ar[i][j] == 'G')
          cnt++;
      }
    }
    if(cnt == 0 && ar[n][m] != 'B'){
      cout << "Yes";
    } else if(nb(n, m) || ar[n][m] == 'B'){
      cout << "No";
    } else{
      ok = 0;
      memset(vis, false, sizeof(vis));
      ff(n, m);
      if(ok < cnt)
        cout << "No";
      else
        cout << "Yes";
    }
    cout << '\n';
  }
  return 0;
}
