#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ld = long double;

void solve() {
  ull a, b;
  cin >> a >> b;
  ull mn = min(a, b), mx = max(a, b);
  assert(mx >= mn);
  if(mn == ULLONG_MAX) {cout << "Voting Ulang" << '\n'; return;}
  ull avg;
  avg = (mn + (mx - mn) / 2);
  if(a%2 != b%2) avg++;
  cerr << avg << '\n';
  if(a > avg) {
    cout << "Tere";
  } else if(b > avg) {
    cout << "Toni";
  } else {
    cout << "Voting Ulang";
  }
  cout << '\n';
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