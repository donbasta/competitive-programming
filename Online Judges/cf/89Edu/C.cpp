#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int n, m;
int ar[35][35];
int lol[70][2];

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
    memset(lol, 0, sizeof(lol));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        cin >> ar[i][j];
        lol[i + j][ar[i][j]]++;
      }
    }
    int ans = 0;
    for(int i = 0; i <= (m + n - 3) / 2; i++) {
      int cur[2];
      for(int j = 0; j < 2; j++) {
        cur[j] = lol[i][j] + lol[m + n - 2 - i][j];
      }
      ans += min(cur[0], cur[1]);
    }
    cout << ans << '\n';
  }

  return 0;
}
