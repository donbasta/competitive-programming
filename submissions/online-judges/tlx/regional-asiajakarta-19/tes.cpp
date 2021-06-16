#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct lol {
	ll x, y;
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  ll a, b;
  cin >> a >> b;
  lol kontol = {a, b};
  cout << kontol.x << ' ' << kontol.y << '\n';
  kontol.x = 5;
  cout << kontol.x << ' ' << kontol.y << '\n';


  return 0;
}
