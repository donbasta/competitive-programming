#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll a, b;
  cin >> a >> b;
  if(a - b > 1) {
    cout << "NO" << '\n';
    return;
  }
  a += b;
  bool ok = true;
  for(ll i = 2; i * i <= a; i++) {
    if(a % i == 0) {
      ok = false;
      break;
    }
  }
  cout << (ok ? "YES" : "NO") << '\n';
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