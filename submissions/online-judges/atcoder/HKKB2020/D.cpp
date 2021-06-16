#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;

ll n, a, b;

inline ll sum(ll x) {
  return (x * (x + 1) / 2) % MOD;
}

inline ll sum(ll x, ll y) {
  // if(x > y) swap(x, y);
  ll ret = (sum(y) - sum(x - 1)) % MOD;
  if(ret < 0) ret += MOD;
  return ret;
} 

void solve() {
  cin >> n >> a >> b;
  if(n < (a + b)) {
    cout << 0 << '\n';
    return;
  }
  if(a < b) swap(a, b);
  if(b == 1) {
    ll ans = (n - a + 1) * (n - a + 1) % MOD;
    ll temp = (n * n - a * a) % MOD;
    ans = (ans * temp) % MOD;
    cout << ans << '\n';
    return;
  }
  ll ans = ((n - a + 1) * (n - b + 1)) % MOD;
  ans = (ans * ans) % MOD;
  

  ll lol = (a - b + 1) * (n - a + 1) % MOD;
  lol = (lol * lol) % MOD;

  ll lel = sum(n - a - b + 2, n - a);
  lel = (lel * (n - a + 1)) % MOD;
  // lel = (lel * (b - 1)) % MOD;
  lel = (lel * (a - b + 1)) % MOD;
  lel = lel * 4 % MOD;
  lol = (lol + lel) % MOD;
  // ll rem = ((n - a + 2 * b - 1) * (a - b + 1)) % MOD;
  ll lul = sum(n - a - b + 2, n - a);
  lul = (lul * lul) % MOD;
  lul = lul * 4 % MOD;
  lol = (lol + lul) % MOD;
  ans = (ans - lol) % MOD;
  // rem = (rem + lul) % MOD;
  // ans = (ans - rem) % MOD;
  if(ans < 0) ans += MOD;
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