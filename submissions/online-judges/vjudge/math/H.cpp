#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const int N = 1e5;

ll val[N + 5];
ll n, k;

ll fastexpo(ll a, ll b) {
  ll res = 1;
  while(b) {
    if(b & 1) { res = (res * a) % MOD; }
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

void solve() {
  cin >> n >> k;
  ll ans = 0;
  for(int i = k; i >= 1; i--) {
    ll temp = fastexpo(k / i, n);
    for(int j = 2 * i; j <= k; j += i) {
      temp -= val[j]; temp %= MOD;
    }
    val[i] = temp;
    ans = (ans + temp * i) % MOD;
  }
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