#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  string s;
  cin >> s;
  int n = (int)s.length();
  int kick = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (i <= n-5) {
      if (s.substr(i, 5) == "START") {
        ans = ans + kick;
      }
    }
    if (i <= n-4) {
      if (s.substr(i, 4) == "KICK") {
        kick++;
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  
  return 0;
}