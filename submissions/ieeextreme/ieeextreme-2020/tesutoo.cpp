#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = double;

void solve() {

  cerr << fixed << setprecision(20);
  for(int i=1; i <=10; i++) {
    cerr << i << ' ' << ((ld)i/sqrt((ld)i*i+(ld)i*i)) << '\n';
  }

  cerr << ((ld)9/sqrt((ld)9*9+(ld)9*9)) << '\n';
  cerr << 9/sqrt(162) << '\n';
  assert(sqrt(162)==sqrt((ld)162));
  cerr << (ld)10/sqrt((ld)200) << '\n';
  cerr << 10/sqrt(200) << '\n';

  ld A = ((ld)10/sqrt((ld)200));
  ld B = ((ld)9/sqrt((ld)162));
  cerr << fixed << setprecision(20) << A << ' ' << B << '\n';
  // assert(A==B);
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