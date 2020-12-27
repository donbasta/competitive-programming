#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll xm, ym, xp, yp, xk, yk;
ll xa, ya, xb, yb;

int cp(ll a, ll b, ll c, ll d) {
  ll lol = a * d - b * c;
  if(lol < 0) return -1;
  else if(lol == 0) return 0;
  else return 1;
}

void solve() {
  cin >> xm >> ym >> xp >> yp >> xk >> yk;
  xa = xp - xm;
  ya = yp - ym;
  xb = xk - xm;
  yb = yk - ym;
  int sgn = cp(xa, ya, xb, yb);
  cout << "rasi ";
  if(sgn == -1) {cout << "anjing";}
  else if(sgn == 0) {cout << "ular";}
  else {cout << "kucing";}
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  
  return 0;
}