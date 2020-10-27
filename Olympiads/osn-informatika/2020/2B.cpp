#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define fi first
#define se second

const int N = 1e5;

struct Circle {
  int x, y, 
}

pair<pair<int, int>, int> pos[N + 5];
int cur, le, ri;

void solve() {
  cin >> n >> xs >> ys >> xf >> yf;
  for(int i = 1; i <= n; i++) {
    cin >> pos[i].fi.fi >> pos[i].fi.se >> r[i] >> c[i];
    pos[i].se = i;
  }
  sort(pos + 1, pos + n + 1);

  cur = 0;
  le = pos[1].fi.fi, ri = pos[1].fi.se;
  while(idx <= n) {

  }


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