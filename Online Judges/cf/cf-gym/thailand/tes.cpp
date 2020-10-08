#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {

  vector<pair<int, int>> ve = {{1, 2}, {1, 4}, {5, -1}, {2, 0}};
  sort(ve.begin(), ve.end());

  cout << lower_bound(ve.begin(), ve.end(), make_pair(1, 3)) - ve.begin() << '\n';

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