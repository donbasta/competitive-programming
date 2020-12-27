#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int dx = 0, dy = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'N') dy++;
    if (s[i] == 'S') dy--;
    if (s[i] == 'W') dx--;
    if (s[i] == 'E') dx++;
  }
  bool ok = 1;
  while (m--) {
    int t, qx, qy;
    cin >> t >> qx >> qy;
    int rep = (t / n);
    int pref = (t % n);
    if (pref == 0) {
      bool cek_x = rep * dx == qx;
      bool cek_y = rep * dy == qy;
      if (!cek_x || !cek_y) {
        ok = 0;
        break;
      } 
    } else {
      //u, d, l, r
      int u, d, l, r;
      int ch_x = qx - rep * dx;
      int ch_y = qy - rep * dy;
      //u - d = qx - rep * dx;
      //r - l = qy - rep * dy;
      //u + d + r + l = pref;
      int ch = ch_x + ch_y;
      if (ch % 2 != 0 || ch > pref) {
        ok = 0;
        break;
      }
      u + r = (ch + pref) / 2;
      d + l = (pref - ch) / 2;
      
    }
  }
  if (!ok) {
    cout << 0 << '\n';
    return;
  }
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