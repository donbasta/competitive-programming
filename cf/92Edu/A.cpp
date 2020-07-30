#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int l, r;

void solve() {
  cin >> l >> r;
  if(r < 2 * l) {
    cout << -1 << ' ' << -1 << '\n';
    return;
  }
  cout << l << ' ' << 2 * l << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}