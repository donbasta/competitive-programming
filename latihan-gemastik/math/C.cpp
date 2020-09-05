#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  // int TC = 1;
  // cin >> TC;
  // for(int i = 1; i <= TC; i++) {
  //   cout << "Case #" << i << ": ";
  //   solve();
  // }
  const ll t = 777;
  ll ret = 1;
  int cnt = 0;
  while(ret < LLONG_MAX / t) {
    ret *= t;
    cnt++;
  }
  cerr << cnt << '\n';
  
  return 0;
}