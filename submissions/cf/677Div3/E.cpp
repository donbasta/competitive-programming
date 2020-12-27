#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

//ans = C(n, n/2) / 2 * ((n/2 - 1)!)^2

ll C(ll a, ll b) {
  if (a < b || a < 0 || b < 0)
    return 0;
  long double ret = 1;
  for (int i = 1; i <= b; i++) {
    ret = ret * (ld) (i + a - b) / (ld) i;
  }
  return roundl(ret);
}

ll fact(ll a) {
  if (a == 0) return 1;
  return a * fact(a - 1);
}

void solve() {
  ll n;
  cin >> n;

  ll ans = C(n, n / 2);
  ans = ans * fact(n / 2 - 1);
  ans = ans * fact(n / 2 - 1);
  ans /= 2;
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