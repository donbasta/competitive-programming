#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int n;
string s;
map<char, int> m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n >> s;
  for(int i = 0; i < n; i++) {
    m[s[i]]++;
  }
  int ans = 2 * min(m['U'], m['D']) + 2 * min(m['L'], m['R']);
  cout << ans << '\n';
  return 0;
}
