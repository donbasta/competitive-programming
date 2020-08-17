#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll x, k, d;

void solve() {
  cin >> x >> k >> d;
  ll need = abs(x) / d;
  ll ans;
  if(x == 0) {
    if(k & 1) {
      ans = d;
    } else {
      ans = 0;
    }
  } else if(k <= need) {
    if(x < 0) {
      ans = x + d * k;
    } else if(x > 0) {
      ans = x - d * k;
    }
  } else {
    if(x < 0) {
      ll temp = -1LL * (abs(x) % d);
      k -= need;
      if(k & 1) {
        ans = d - abs(temp);
        else ans = abs(temp);
      }
    } else if(x > 0) {

    }
  }
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