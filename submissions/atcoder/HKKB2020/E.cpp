#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const int N = 2e3;

ll fastexpo(ll a, ll b) {
  ll ret = 1;
  while(b) {
    if(b & 1) { ret = ret * a % MOD; }
    a = a * a % MOD;
    b >>= 1;
  }
  return ret;
}

int h, w, k;
string st[N + 5];
int hr[N + 5][N + 5][2], vr[N + 5][N + 5][2];

void solve() {
  cin >> h >> w;
  for(int i = 0; i < h; i++) {
    cin >> st[i];
    for(int j = 0; j < w; j++) {
      k += (st[i][j] == '.');
    }
  }
  for(int i = 0; i < h; i++) {
    int ed;
    ed = 0;
    for(int j = 0; j < w; j++) {
      if(st[i][j] == '#') ed = j + 1;
      else {
        hr[i][j][0] = ed;
      }
    }
    ed = w + 1;
    for(int j = w - 1; j >= 0; j--) {
      if(st[i][j] == '#') ed = j + 1;
      else {
        hr[i][j][1] = ed;
      }
    }
  }
  for(int i = 0; i < w; i++) {
    int ed;
    ed = 0;
    for(int j = 0; j < h; j++) {
      if(st[j][i] == '#') ed = j + 1;
      else {
        vr[j][i][0] = ed;
      }
    }
    ed = h + 1;
    for(int j = h - 1; j >= 0; j--) {
      if(st[j][i] == '#') ed = j + 1;
      else {
        vr[j][i][1] = ed;
      }
    }
  }
  ll ans = 0;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(st[i][j] == '#') continue;
      int ni = i + 1, nj = j + 1;
      int tot_hr = hr[i][j][1] - hr[i][j][0] - 1;
      int tot_vr = vr[i][j][1] - vr[i][j][0] - 1;
      // cerr << i << ' ' << j << ' ' << tot_hr << ' ' << tot_vr << '\n';
      // for(int x = 0; x < 2; x++) {
      //   cerr << hr[i][j][x] << ' ' << vr[i][j][x] << '\n';
      // }
      int tot = tot_hr + tot_vr - 1;
      ll temp = (fastexpo(2, k) - fastexpo(2, k - tot));
      ans = (ans + temp) % MOD;
    }
  }
  if(ans < 0) ans += MOD;
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