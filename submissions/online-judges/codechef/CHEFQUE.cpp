#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const unsigned int SZ = 1 << 31;
const ll MOD = 1LL << 32;
bitset<SZ> bi;
ll sum = 0;
ll q, s, a, b;

void solve() {

  cin >> q >> s >> a >> b;

  while(q--) {
    ll hs = s / 2;
    if(s & 1) {
      if(!bi.test(hs)) {
        sum += hs, bi.set(hs);
      }
    } else {
      if(bi.test(hs)) {
        sum -= hs, bi.reset(hs);
      }
    }
    s = (a * s + b) % MOD;
  }
  cout << sum << '\n';
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