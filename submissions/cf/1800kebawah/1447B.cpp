#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int m, n;
  cin >> n >> m;

  vector<int> mn(2, 101), tmp(2), neg(2);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      int par = (i + j) % 2;
      tmp[par] += abs(x); 
      mn[par] = min(mn[par], abs(x));
      if (x < 0) {
        neg[par]++;
      }
    }
  }
  int ans = 0;
  int Mn = min(mn[0], mn[1]);
  if (Mn == 0) {
    ans = tmp[0] + tmp[1];
  } else {
    int Neg = neg[0] + neg[1];
    if (Neg % 2 == 1) {
      ans = tmp[0] + tmp[1] - 2 * Mn;
    } else {
      ans = tmp[0] + tmp[1];
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}