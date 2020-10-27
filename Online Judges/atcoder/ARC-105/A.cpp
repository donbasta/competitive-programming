#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  vector<int> ve(4);
  int sum = 0;
  for(int i = 0; i < 4; i++) {
    cin >> ve[i];
    sum += ve[i];
  }
  sort(ve.begin(), ve.end());
  bool ok = 0;
  ok |= (2 * (ve[0] + ve[3]) == sum);
  ok |= (2 * (ve[0] + ve[1] + ve[2]) == sum);
  cout << (ok ? "Yes" : "No") << '\n';
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