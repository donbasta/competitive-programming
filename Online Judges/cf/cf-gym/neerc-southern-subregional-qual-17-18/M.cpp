#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<int> t(n);
  for(int i = 0; i < n; i++) {
    cin >> t[i];
  }
  bool ok = true;
  int d = t[1] - t[0];
  for(int i = 2; i < n; i++) {
    ok &= (d == t[i] - t[i - 1]);
  }
  int ans;
  if(!ok) {
    ans = t[n - 1];
  } else {
    ans = t[n - 1] + d;
  }
  cout << ans << '\n';
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