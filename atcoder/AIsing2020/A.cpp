#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main() {
  int l, r, d;
  cin >> l >> r >> d;
  int ans = r / d - (l - 1) / d;
  cout << ans << '\n';
  return 0;
}