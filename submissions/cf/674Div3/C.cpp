#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  //k + r => (k+1)(r+1) >= n
  int ans = 2e9;
  for(int i = 0; i * i <= n; i++) {
    int t = i + 1;
    int t2 = (n + t - 1) / t;
    ans = min(ans, i + t2 - 1);
  }
  cout << ans << '\n';
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