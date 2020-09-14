#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ld eps = 1e-9;

ld ar[4];

inline ld sq(ld x) { return x * x; }

inline ld f(ld x) {
  ld cs[2];
  for(int i = 0; i < 2; i++) {
    cs[i] = (sq(ar[i * 2]) + sq(ar[i * 2 + 1]) - sq(x)) / (ar[i * 2] * ar[i * 2 + 1] * ((ld)2.0));
    cs[i] = sqrtl(1 - sq(cs[i]));
  }
  return (ar[0] * ar[1] * cs[0] + ar[2] * ar[3] * cs[1]) / ((ld)2.0);
}


inline ld ternary_search(ld l, ld r) {
  while((r - l) > eps) {
    ld m1 = l + (r - l) / 3;
    ld m2 = r - (r - l) / 3;
    ld fm1 = f(m1);
    ld fm2 = f(m2);
    if(fm1 < fm2) { l = m1; }
    else { r = m2; }
  }
  return f(l);
}

inline void solve() {

  cout << fixed << setprecision(10);
  for(int i = 0; i < 4; i++) { cin >> ar[i]; }
  sort(ar, ar + 4);
  ld mn = (max(ar[1] - ar[0], ar[3] - ar[2]));
  ld mx = (ar[0] + ar[1]);
  ld ans = ternary_search(mn, mx);
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