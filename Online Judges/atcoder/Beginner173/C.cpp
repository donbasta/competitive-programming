#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int ans = 0;
  int h, w, K;
  cin >> h >> w >> K;

  // int bl = 0;
  vector<vector<char>> ve(h, vector<char>(w));
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      cin >> ve[i][j];
      // if(ve[i][j] == '#')
      //   bl++;
    }
  }

  int mh = (1 << h) - 1;
  int mw = (1 << w) - 1;
  for(int i = 0; i <= mh; i++) {
    for(int j = 0; j <= mw; j++) {
      vector<vector<char>> temp = ve;
      int cur = 0;
      for(int k = 0; k < h; k++) {
        if((i >> k) & 1) {
          for(int kk = 0; kk < w; kk++) {
            temp[k][kk] = '.';
          }
        }
      }
      for(int l = 0; l < w; l++) {
        if((j >> l) & 1) {
          for(int ll = 0; ll < h; ll++) {
            temp[ll][l] = '.';
          }
        }
      }
      for(int k = 0; k < h; k++) {
        for(int l = 0; l < w; l++) {
          if(temp[k][l] == '#')
            cur++;
        }
      }
      if(cur == K)
        ans++;
    }
  }
  cout << ans << '\n';

  return 0;
}
