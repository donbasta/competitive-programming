#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

bool intersect(int a, int b, int c, int d) {
  if(b < c || d < a)
    return false;
  return true;
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
    int n, x, m;
    cin >> n >> x >> m;
    int mn = x, mx = x;
    for(int i = 0; i < m; i++) {
      int l, r;
      cin >> l >> r;
      if(intersect(l, r, mn, mx)) {
        mn = min(mn, l);
        mx = max(mx, r);
      }
    }
    cout << mx - mn + 1 << '\n';
  }

  return 0;
}
