#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, init;
  cin >> n;
  cin >> init;
  bool ok = true;
  for(int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    ok &= (x == init);
  }
  cout << (ok ? n : 1) << '\n';
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