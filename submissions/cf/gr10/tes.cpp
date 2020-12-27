#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll lol =  (1LL << 51) * 3;
  // lol = (1LL << 50);
  // assert(lol < 1LL * )
  cout << lol << '\n';
  cout << lol - 1LL * 10000000000000000 << '\n';
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