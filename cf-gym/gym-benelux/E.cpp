#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const int M = 5e3;

ll fc[M + 5], ifc[M + 5];

ll fast_expo(ll a, ll b) {
  ll ret = 1;
  while(b) {
    if(b & 1) { ret = ret * a % MOD; }
    a = a * a % MOD;
    b >>= 1; 
  }
  return ret;
}

void init_fac() {
  fc[0] = 1;
  for(int i = 1; i <= M; i++) { fc[i] = fc[i - 1] * i % MOD; }
  ifc[M] = fast_expo(fc[M], MOD - 2);
  for(int i = M - 1; i >= 0; i--) { ifc[i] = ifc[i + 1] * (i + 1) % MOD; }
}

ll C(ll a, ll b) {
  if(a < b || a < 0 || b < 0) return 0;
  ll ret = fc[a];
  ret = (ret * ifc[a - b]) % MOD;
  ret = (ret * ifc[b]) % MOD;
  return ret;
}

inline void solve() {

  init_fac();

  int n;
  cin >> n;

  map<ll, ll> cnt;
  for(int i = 1; i <= n; i++) {
    ll x;
    cin >> x;
    cnt[x]++;
  }
  if((int)cnt.size() == 1) {
    cout << 0 << '\n'; return;
  }
  ll ans = 0;
  ll pref = cnt.begin()->second;
  ll bawah = ifc[pref];
  for(auto it = cnt.begin(); it != cnt.end(); ++it) {
    auto nit = it; ++nit;
    if(nit == cnt.end()) break;
    ll temp = ans;
    ans = (temp * C(nit->second + pref - 2, pref - 2)) % MOD;
    ans = ((ans % MOD) + ((C(nit->second + pref - 2, pref - 1) * fc[pref] % MOD) * bawah) % MOD) % MOD;
    bawah = (bawah * ifc[nit->second]) % MOD;
    pref = (pref + nit->second);
    cerr << ans << '\n';
  }
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