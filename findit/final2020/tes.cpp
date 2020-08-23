#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;

ll fastexpo(ll a, ll b, ll m = MOD) {
  ll ret = 1;
  while(b) {
    if(b & 1) {ret = (ret * a) % m;}
    a = (a * a) % m;
    b >>= 1;
  }
  ret %= m;
  if(ret < 0) ret += m;
  return ret;
}

ll discrete_log(ll a, ll b, ll m) {
  a %= m, b %= m;
  ll n = sqrtl(m) + 1;

  ll an = 1;
  for (ll i = 0; i < n; ++i)
    an = (an * a) % m;

  unordered_map<ll, ll> vals;
  for (ll q = 0, cur = b; q <= n; ++q) {
    vals[cur] = q;
    cur = (cur * a) % m;
    if(cur < 0) cur += m;
  }

  for (ll p = 1, cur = 1; p <= n; ++p) {
    cur = (cur * an) % m;
    if(cur < 0) cur += m;
    if(vals.count(cur)) {
      ll ans = n * p - vals[cur];
      ans %= (m - 1);
      if(ans < 0) ans += (m - 1);
      return ans;
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  for(int i = 0; i < 4; i++) {
    ll a, b, m;
    cin >> a >> b >> m; //m prima
    cerr << i << '\n';
    assert(discrete_log(a, fastexpo(a, b, m), m) == b % (m - 1));
    cout << "yes" << '\n';
  }



  
  return 0;
}