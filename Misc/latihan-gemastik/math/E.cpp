#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ld fastexpo(ld a, int n) {
  ld ret = (ld)1.0;
  while(n) {
    if(n & 1) ret = ret * a;
    a = a * a;
    n >>= 1;
  }
  return ret;
}

void solve() {
  cout << fixed << setprecision(9);
  int n, m;
  cin >> m >> n;
  ld ans = (ld) m;
  for(int i = 1; i <= m - 1; i++) {
    ld now = ((ld)1.0) - ((ld)i) / ((ld)m);
    ld temp = fastexpo(now, n);
    ans -= temp;
  }
  cout << ans << '\n';
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