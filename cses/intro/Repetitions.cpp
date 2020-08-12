#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  string s;
  cin >> s;
  int ans = -1, cur = 0;
  char now = ' ';
  for(auto& c : s) {
    if(c == now) {
      cur++;
    } else {
      now = c;
      ans = max(ans, cur);
      cur = 1;
    }
  }
  ans = max(ans, cur);
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