#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;

ll fastexpo(ll a, ll b) {
  ll ret = 1;
  while(b) {
    if(b & 1) {ret = (ret * a) % MOD;}
    a = (a * a) % MOD;
    b >>= 1;
  }
  return ret;
}

void solve() {
  int n;
  cin >> n;
  ll ans = 1;
  for(int i = 1; i <= n; i++) {
    ans = (ans * i) % MOD;
  }
  ans -= fastexpo(2LL, n - 1);
  ans %= MOD;
  if(ans < 0) ans += MOD;
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