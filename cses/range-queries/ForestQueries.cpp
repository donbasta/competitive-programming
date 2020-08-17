#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e3;

int pre[N + 5][N + 5];
int n, q;

void solve() {
  cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      char c;
      cin >> c;
      pre[i][j] = (c == '*');
      pre[i][j] += (pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1]);
    }
  }
  while(q--) {
    int x1, x2, y1, y2;
    cin >> y1 >> x1 >> y2 >> x2;
    int ans = pre[y2][x2] - pre[y1 - 1][x2] - pre[y2][x1 - 1] + pre[y1 - 1][x1 - 1];
    cout << ans << '\n';
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