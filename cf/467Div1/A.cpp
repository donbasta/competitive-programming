#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> k >> d >> t;
  if(d >= k) {
  	ll e = d - k;
  	ld one = ((ld) k / (ld) t) + ((ld) e / (ld) (2.0 * t));
  	ll tot = floor((ld) 1.0 / one);
  	t -= tot;
  	
  }

  return 0;
}
