#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;

ll P(ll a, ll b) {
  // a * (a-1) * ... * (a-b+1);
  ll ret = 1;
  for (int i = 0; i < b; i++) {
    ret = (ret * (a - i)) % MOD;
  }
  return ret;
}

void solve() {
  int n, x, pos;
  cin >> n >> x >> pos;

  int a = 0, b = 0;
  int l = 0, r = n;
  while (l < r) {
    int m = (l + r) >> 1;
    if (m <= pos) { //a[m] <= x
      a++;
      l = m + 1;
    } else {
      b++;
      r = m;
    }
  }
  assert(l - 1 == pos);

  ll ans = P(x - 1, a - 1);
  ans = (ans * P(n - x, b)) % MOD;
  ans = (ans * P(n - a - b, n - a - b)) % MOD;
  if (ans < 0) ans += MOD;
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