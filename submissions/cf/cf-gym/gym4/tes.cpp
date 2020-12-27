#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;


const ll MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  ll c = 56;
  for(int i = 0; i < 5; i++) {
  	c = c * 25 % MOD;
  }
  cout << c << '\n';

  return 0;
}
