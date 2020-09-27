#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  int sel = y - x;
  for(int i = 1; i <= sel; i++) {
    if(sel % i != 0) continue;
    int total = (sel / i) + 1;
    if(total > n) continue;
    vector<int> ve;
    for(int j = x; j <= y; j += i) {
      ve.push_back(j);
    }
    int cur = x - i;
    bool at = 0;
    while((int)ve.size() < n) {
      if(cur <= 0) { cur = y + i; at = 1; }
      ve.push_back(cur);
      if(at) { cur += i; }
      else { cur -= i; }
    }
    sort(ve.begin(), ve.end());
    for(auto i : ve) {
      cout << i << ' ';
    }
    cout << '\n';
    break;
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