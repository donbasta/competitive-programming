#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll ax, ay, bx, by, k, da;

ll getX(ll y) {
  return (da + by * ax - ay * bx - y * (ax - bx)) / (by - ay);
}

ll getY(ll x) {
  return (da + by * ax - ay * bx - x * (by - ay)) / (ax - bx);
}

void solve() {
  cin >> ax >> ay >> bx >> by >> k;
  da = __gcd(abs(ax - bx), abs(ay - by));
  vector<ll> ve;
  if(ax == bx) {
    int cur = 1, cnt = 0;
    while(cnt < k) {
      // if(__gcd(abs(cur - ay), da) > 1) { cur++; continue; }
      // else {
        ve.push_back(cur);
        cnt++, cur++;
      // }
    }
    for(auto y : ve) {
      ll x = getX(y);
      cout << x << ' ' << y << '\n';
    }
  } else {
    int cur = 1, cnt = 0;
    while(cnt < k) {
      // if(__gcd(abs(cur - ax), da) > 1) { cur++; continue; }
      // else {
        ve.push_back(cur);
        cnt++, cur++;
      // }
    }
    for(auto x : ve) {
      ll y = getY(x);
      cout << x << ' ' << y << '\n';
    }
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