#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

int ar[60][60];
int r[60], c[60];
int sum, mn = INF, mx = -INF;

void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin >> ar[i][j];
    }
  }
  int q;
  cin >> q;
  while(q--) {
    string s;
    int k, val;
    cin >> s >> k >> val;
    if(s == "row") { r[k] += val; }
    else { c[k] += val; }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      ar[i][j] = ar[i][j] + r[i] + c[j];
      mx = max(mx, ar[i][j]);
      mn = min(mn, ar[i][j]);
      sum += ar[i][j];
    }
  }
  cout << sum << ' ' << mn << ' ' << mx << '\n';
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