#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using cd = complex<long double>;

const ld PI = acos(-1);
string s, t;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> s >> t;
  int s1 = (int)s.length();
  int t1 = (int)t.length();
  assert(t1 <= s1);
  int ans = 0;
  for(int i = 0; i <= s1 - t1; i++) {
  	bool ok = true;
  	for(int j = 0; j < t1; j++) {
      ok &= (t[j] != s[i + j]);
  	}
    if(ok)
      ans++;
  }
  cout << ans << '\n';
  return 0;
}
