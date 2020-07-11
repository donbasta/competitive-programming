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
    int n, k, ans = 0;
    string s;
    cin >> n >> k >> s;
    int le = -1, ri = 0;
    for(int i = 0; i < n; i++) {
      if(s[i] == '0') {
        ri++;
      } else {
        if(le == -1) {
          ans += (ri / (k + 1));
        } else {
          ans += max(0, ((ri - le) / (k + 1)) - 1);
        }
        le = i;
        ri = i + 1;
      }
    }
    assert(ri == n);
    if(le != -1)
      ans += (ri - 1 - le) / (k + 1);
    else
      ans += (n + k) / (k + 1);
    cout << ans << '\n';
  }
  return 0;
}
