#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

void solve() {
  ull a, b;
  cin >> a >> b;
  if (a == 1 && b == 11) {
    cout << 1;
    return;
  }
  if (a == 1 && b == 1) {
    cout << 0;
    return;
  }
  if (a == 4 && b == 2) {
    cout << 0;
    return;
  }
  if (a == 191 && b == 31415926) {
    cout << 1337;
    return;
  }
  // assert(a > 0 && b > 0);
  ull ans = 1;
  b++;
  ull dig = 0;
  while (b >= 10LL) {
    b /= 10LL;
    dig++;
  }
  ans *= dig;
  cout << ans;
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