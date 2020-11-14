#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e5;

void solve() {
  int n;
  cin >> n;

  int L = -INF, R = INF, U = INF, D = -INF;

  for (int i = 0; i < n; i++) {
    int f[4];
    int x, y;
    cin >> x >> y;
    for (int j = 0; j < 4; j++) {
      cin >> f[j];
    }
    if (!f[0]) {
      L = max(L, x);
    }
    if (!f[1]) {
      U = min(U, y);
    }
    if (!f[2]) {
      R = min(R, x);
    }
    if (!f[3]) {
      D = max(D, y);
    }
  }

  if (L > R || U < D) {
    cout << 0;
  } else {
    cout << 1 << ' ' << L << ' ' << D;
  }
  cout << '\n';
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