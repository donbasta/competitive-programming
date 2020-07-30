#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  string s;
  cin >> s;
  int len = (int)s.length(), beta = 0;
  assert(s[0] == 'A');
  for(int i = 1; i < len; i++) {
    beta += (s[i] == 'B');
  }
  bool ok = true;
  ok &= (beta >= len / 2);
  ok &= (beta < len - 1);
  cout << (ok ? "Y" : "N") << '\n';
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