#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int b, w;
  cin >> b >> w;
  int dif = abs(b - w);
  //(n+1)^2, n^2, dif = 2n+1, mm >= dif/2
  if (min(b, w) < dif / 2) {
    cout << "NO";
  } else {
    cout << "YES" << '\n';
    pair<int, int> init;
    if (b < w) {
      init = make_pair(1, 1);
    } else {
      init = make_pair(1, 2);
    }
    for (int i = )
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