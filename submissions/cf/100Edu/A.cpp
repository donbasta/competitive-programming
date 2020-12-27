#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int mn = min({a, b, c});
  int sum = (a + b + c); 
  bool ok = (sum % 9 == 0) && (9 * mn >= sum);
  cout << (ok ? "YES" : "NO");
  cout << '\n';
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