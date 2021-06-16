#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  string s;
  cin >> s;
  int n = (int)s.length();

  if (n == 3) {
    cout << 0 << '\n';
    return;
  }

  int ans = 4;
  bool rg = 0, gb = 0, br = 0;
  bool RG = 0, GB = 0, BR = 0;
  bool r = 0, g = 0, b = 0;

  for (int i = 0; i <= n-2; i++) {
    if (s[i]=='R' && s[i+1]=='G') {
      rg = 1;
      if (i == 0 || i == n-2) RG = 1;
    }
    if (s[i]=='G' && s[i+1]=='R') {
      rg = 1;
      if (i == 0 || i == n-2) RG = 1;
    }
    if (s[i]=='R' && s[i+1]=='B') {
      br = 1;
      if (i == 0 || i == n-2) BR = 1;
    }
    if (s[i]=='B' && s[i+1]=='R') {
      br = 1;
      if (i == 0 || i == n-2) BR = 1;
    }
    if (s[i]=='G' && s[i+1]=='B') {
      gb = 1;
      if (i == 0 || i == n-2) GB = 1;
    }
    if (s[i]=='B' && s[i+1]=='G') {
      gb = 1;
      if (i == 0 || i == n-2) GB = 1;
    }
  }

  if (s[0] == 'R' || s[n-1] == 'R') r = 1;
  if (s[0] == 'G' || s[n-1] == 'G') g = 1;
  if (s[0] == 'B' || s[n-1] == 'B') b = 1;

  if (r && gb) ans = min(ans, 3);
  if (g && br) ans = min(ans, 3);
  if (b && rg) ans = min(ans, 3);
  if (GB) ans = min(ans, 3);
  if (BR) ans = min(ans, 3);
  if (RG) ans = min(ans, 3);
  if (r && GB) ans = min(ans, 2);
  if (g && BR) ans = min(ans, 2);
  if (b && RG) ans = min(ans, 2);

  for (int i = 0; i <= n-3; i++) {
    int R = 0, G = 0, B = 0;
    for (int j = 0; j < 3; j++) {
      if (s[i+j] == 'R') R++;
      if (s[i+j] == 'G') G++;
      if (s[i+j] == 'B') B++;
    }
    if (R>0 && G>0 && B>0) {
      if (i == 0 || i == n-3) {
        ans = min(ans, 1);
      } else {
        ans = min(ans, 2);
      }
    }
  }
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