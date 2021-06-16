#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll n;
  cin >> n;
  if (n == 1) {
    cout << 0 << '\n';
    return;
  }
  if (n == 2) {
    cout << 1 << '\n';
    return;
  }
  if (n == 3) {
    cout << 2 << '\n';
    return;
  }
  if (n % 2 == 0) {
    cout << 2 << '\n';
    return;
  }
  if (n % 2 == 1) {
    cout << 3 << '\n';
    return;
  }
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