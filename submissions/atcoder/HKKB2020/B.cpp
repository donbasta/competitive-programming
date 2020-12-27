#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int h, w;
string st[105];

void solve() {
  cin >> h >> w;
  for(int i = 0; i < h; i++) {
    cin >> st[i];
  }
  int ans = 0;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(st[i][j] == '#') continue;
      if(j < w - 1){
        if(st[i][j + 1] == '.') ans++;
      }
      if(i < h - 1){
        if(st[i + 1][j] == '.') ans++;
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