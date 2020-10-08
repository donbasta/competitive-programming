#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  string s, t;
  cin >> s >> t;
  int ans = 0;
  for(int i = 0; i < (int)s.length(); i++) {
    if(s[i] != t[i])
      ans++;
  }
  cout << ans << '\n';

  return 0;
}
