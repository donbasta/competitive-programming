#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

inline ld f(int a, int b) { return ((ld)a) / ((ld)b); }

const int N = 3000;

int cnt[N + 5];

inline void solve() {
  int n, k;
  cin >> n >> k;
  fill(cnt + 1, cnt + n + 1, 0);
  for(int i = 1; i <= k; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  int p = 0, q = 0, r = 0;
  for(int i = 1; i <= n; i++) {
    if(cnt[i] == 0) { p++; }
    else if(cnt[i] == 1) { q++; }
    else { r++; }
  }
  assert(p + q + r == n);
  if(r == n) {
    cout << 0 << '\n';
    return;
  }
  ld E[n + 1][n + 1];
  E[q][r] = 0;
  for(int i = q + 1; i <= n - r; i++) {
    E[i][r] = (r > 0 ? E[i + 1][r - 1] * f(i + 1, n - r) : 0) + E[i - 1][r] * f(n - r - i + 1, n - r) + f(n, n - r);
  }
  for(int i = r + 1; i < n; i++) {
    E[0][i] = E[1][i - 1] * f(1, n) + 1;
    for(int j = 1; j <= n - i; j++) {
      E[j][i] = (i > 0 ? E[j + 1][i - 1] * f(j + 1, n - i) : 0) + (j > 0 ? E[j - 1][i] * f(n - i - j + 1, n - i) : 0) + f(n, n - i);
    }
  }
  E[0][n] = E[1][n - 1] * f(1, n) + 1;
  cout << E[0][n] << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cout << fixed << setprecision(12);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}