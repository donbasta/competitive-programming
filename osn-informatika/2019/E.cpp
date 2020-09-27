#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void ask(int x, int y) {
  cout << '?' << ' ' << x << ' ' << y << endl;
}

void answer(int x, int y, int z, int t) {
  cout << '!' << ' ' << x << ' ' << y << ' ' << z << ' ' << t << endl;
  exit(0);
}

void solve() {

  int a[4], t[4];
  int r, c, q;

  cin >> r >> c >> q;
  assert(q >= 5);
  ask(1, 1);
  cin >> t[0];
  ask(1, c);
  cin >> t[1];
  ask(r, 1);
  cin >> t[2];
  ask(r, c);
  cin >> t[3];

  a[0] = 1 + 1 + t[0];
  a[1] = 1 - c + t[1];
  a[2] = r - 1 - t[2];
  a[3] = r + c - t[3];

  //x+y = t[0]+2
  //x-y = 1-c+t[1]
  //x-y = r-1-t[2]
  //x+y = r+c-t[3]

  int pp, qq, rr, ss;

  if((a[0] - a[1]) % 2 == 0) {
    assert((a[2] - a[3]) % 2 == 0);
    pp = (a[0] + a[1]) / 2;
    qq = (a[0] - a[1]) / 2;
    rr = (a[3] + a[2]) / 2;
    ss = (a[3] - a[2]) / 2;
    if(1 <= pp && pp <= r && 1 <= qq && qq <= c) {
      ask(pp, qq);
      int cek;
      cin >> cek;
      if(cek == 0) {
        answer(pp, qq, rr, ss);
      }
    }
    assert((a[0] - a[2]) % 2 == 0);
    pp = (a[0] + a[2]) / 2;
    qq = (a[0] - a[2]) / 2;
    rr = (a[3] + a[1]) / 2;
    ss = (a[3] - a[1]) / 2;
    answer(pp, qq, rr, ss);
  } else {
    assert((a[0] - a[2]) % 2 == 0);
    pp = (a[0] + a[2]) / 2;
    qq = (a[0] - a[2]) / 2;
    rr = (a[3] + a[1]) / 2;
    ss = (a[3] - a[1]) / 2;
    answer(pp, qq, rr, ss);
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