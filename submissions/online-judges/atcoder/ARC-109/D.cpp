#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll f1(ll a, ll b, ll tipe) {
  ll ret;
  if (tipe == 1) {
    if (a == b) ret = 2 * a + (a > 0);
    else ret = min(a, b) * 2 + abs(a - b) * 2;
  }
  if (tipe == 2) {
    if (a == b) ret = 2 * a + 1;
    else if (b > a) ret = min(a, b) * 2 + abs(a - b) * 2 + 2; 
    else if (b < a) ret = min(a, b) * 2 + abs(a - b) * 2; 
    
  }
  if (tipe == 3) {
    if (a == b) ret = 2 * a + 2;
    else if (b < a) ret = min(a, b) * 2 + abs(a - b) * 2;
    else if (b > a) ret = min(a, b) * 2 + abs(a - b) * 2 + 2;     
  }
  if (tipe == 4) {
    ret = min(a, b) * 2 + abs(a - b) * 2 + 1;       
  }
  return ret;
}

int f2(ll a, ll b, ll tipe) {
  ll ret;
  if (tipe == 1) {
    if (a == b) ret = 2 * a + 2;
    else if (b < a) ret = min(a, b) * 2 + abs(a - b) * 2 + 2;
    else if (b > a) ret = min(a, b) * 2 + abs(a - b) * 2; 
  }
  if (tipe == 2) {
    ret = min(a, b) * 2 + abs(a - b) * 2 + 1; 
  }
  if (tipe == 3) {
    if (a == b) ret = 2 * a + 1;
    else ret = min(a, b) * 2 + abs(a - b) * 2; 
  }
  if (tipe == 4) {
    if (a == b) ret = 2 * a + 1;
    else if (b > a) ret = min(a, b) * 2 + abs(a - b) * 2; 
    else if (b < a) ret = min(a, b) * 2 + abs(a - b) * 2 + 2; 
  }
  return ret;
}

void solve() {
  map<pair<ll, ll>, ll> mp;
  ll ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  mp[{ax, ay}] = 1;
  mp[{bx, by}] = 1;
  mp[{cx, cy}] = 1;
  ll ux = max({ax, bx, cx});
  ll vx = min({ax, bx, cx});
  ll uy = max({ay, by, cy});
  ll vy = min({ay, by, cy});
  ll tipe = 0;
  if (!mp.count({ux, uy})) tipe = 1;
  if (!mp.count({ux, vy})) tipe = 2;
  if (!mp.count({vx, uy})) tipe = 3;
  if (!mp.count({vx, vy})) tipe = 4;
  assert(tipe);
  ll ans = 0;
  if (vx >= 0 && vy >= 0) {
    ans = f1(vx, vy, tipe);
  }
  if (ux <= 0 && vy >= 0) {
    ans = f2(-ux, vy, tipe);
  }
  if (vx >= 0 && uy <= 0) {
    ans = f2(vx, -uy, tipe);
  }
  if (ux <= 0 && uy <= 0) {
    ans = f1(-ux, -uy, tipe) + 1;
  }
  cout << ans << '\n';
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