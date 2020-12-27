#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e8 + 37;

ll fast_expo(ll a, ll b, ll mod) {
  ll ret = 1;
  while(b) {
    if(b & 1) { ret = (ret * a) % mod; }
    a = (a * a) % mod;
    b >>= 1;
  }
  return ret;
}

// 38353716

void solve() {
  int n = 10000;
  cout << n << '\n';
  for(int i = 1; i <= n; i++) {
    cout << 2 << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  // cin >> TC;
  for(int i = 1; i <= TC; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  
  return 0;
}