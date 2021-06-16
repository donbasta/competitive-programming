#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int r1, r2, c1, c2;

void solve() {
  cin >> r1 >> c1 >> r2 >> c2;
  int king = max(abs(r2 - r1), abs(c2 - c1));
  int rook = (r1 == r2 || c1 == c2 ? 1 : 2);
  int bishop = (r1 + c1 == r2 + c2 || r1 - c1 == r2 - c2 ? 1 : (r1 + r2 + c1 + c2) % 2 == 0 ? 2 : 0);
  cout << rook << ' ' << bishop << ' ' << king << '\n';
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