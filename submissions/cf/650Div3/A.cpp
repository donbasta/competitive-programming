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

  int tc;
  cin >> tc;
  while(tc--) {
    string s;
    cin >> s;
    int sz = (int) s.length();
    string ans = "";
    for(int i = 0; i < sz; i += 2) {
      ans += s[i];
    }
    ans += s[sz - 1];
    cout << ans << '\n';
  }

  return 0;
}
