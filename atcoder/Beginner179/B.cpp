#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;

  vector<bool> ok(n);
  for(int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    ok[i] = (x == y);
  }
  for(int i = 0; i < n - 2; i++) {
    if(ok[i] && ok[i + 1] && ok[i + 2]) {
      cout << "Yes" << '\n';
      return;
    }
  }
  cout << "No" << '\n';
  return;
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