#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;

ll fast_expo(ll a, ll b, ll mod) {
  ll ret = 1;
  while(b) {
    if(b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}

void solve() {
  ll a, b, c;
  cin >> a >> b >> c;
  ll pw = fast_expo(b, c, MOD - 1);
  ll ans = fast_expo(a, pw, MOD);
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