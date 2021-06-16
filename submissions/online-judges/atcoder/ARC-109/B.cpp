#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll n;
  cin >> n;
  ll l = 1, r = 2e9, ans = 1;
  while (l <= r) {
    ll mid = (l + r) / 2;
    if (mid * (mid - 1) / 2 > n + 1) {
      r = mid - 1;
    } else {
      ans = mid;
      l = mid + 1;
    }
  }
  cout << n - ans + 2 << '\n';
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