#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll n;

ll fastpow(ll a, ll b) {
  ll ret = 1;
  while(b) {
    if(b & 1) {ret = ret * a;}
    a = a * a;
    b >>= 1;
  }
  return ret;
}

void solve() {
  cin >> n;
  ll bit = __builtin_popcountll(n);
  ll ans = fastpow(2LL, bit);
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