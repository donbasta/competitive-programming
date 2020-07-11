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

  int tc;
  cin >> tc;
  while(tc--) {
  	ll a, b, c;
  	cin >> a >> b >> c;
  	ll ans1 = -1, ans2 = -1;
  	if(a * b < c) {
  		ans1 = b;
  	} else if(a * b == c) {
  		ans1 = 1;
  	} else {
  		if(a < c)
  			ans1 = 1;
  		ans2 = b;
  	}
  	cout << ans1 << ' ' << ans2 << '\n'; 
  }
  return 0;
}
