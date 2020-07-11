#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main() {

  int n;
  cin >> n;
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    bool ok = true;
    int x;
    cin >> x;
    ok &= (i & 1);
    ok &= (x & 1);
    ans += ok;
  }
  cout << ans << '\n';
  return 0;
}