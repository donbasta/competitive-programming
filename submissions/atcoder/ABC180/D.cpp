#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll x, y, a, b;
  cin >> x >> y >> a >> b;
  ll exp = 0;
  if(x >= (y+a-1)/a) {
    cout << (y-x-1)/b << '\n';
    return;
  }
  while(x*a <= x+b && x*a < y) {
    x *= a;
    exp++;
  }
  exp += (y-x-1)/b;
  cout << exp << '\n';
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