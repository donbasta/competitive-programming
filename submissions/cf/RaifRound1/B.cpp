#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  int ki = 0, ka = 0;
  for(auto& c : s) {
    ki += c == '<';
    ka += c == '>';
  }
  int ans = 0;
  if(ki == 0 || ka == 0) {
    ans = n;
  } else {
    for(int i = 0; i < n; i++) {
      int ni = (i + 1) % n;
      ans += ((s[i] == '-') || (s[ni] == '-'));
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
    solve();
  }
  
  return 0;
}