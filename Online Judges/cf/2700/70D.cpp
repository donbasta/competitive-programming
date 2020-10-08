#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct Point {
  ll x, y;
}

int t, q;

void solve() {
  cin >> q;
  cin >> t >> ox >> oy;
  for(int i = 0; i < 2; i++) {
    int x, y;
    cin >> t >> x >> y;
    se.emplace(, Point(x, y));
  }
  q -= 3;
  while(q--) {
    int x, y;
    cin >> t >> x >> y;
    if(t == 1) {
      ld angle = ...
      
    } else if(t == 2) {

    }
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