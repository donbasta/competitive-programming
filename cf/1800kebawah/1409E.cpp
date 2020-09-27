#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

inline void solve() {
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ve.push_back(x);
  }
  for(int i = 0; i < n; i++) {
    int _; cin >> _;
  }
  sort(ve.begin(), ve.end());
  vector<int> temp;
  int sz = 0;
  for(int i = 0; i < n; i++) {
    if(i > 0 && ve[i] == ve[i - 1]) continue;
    int l = ve[i];
    int r = ve[i] + k;
    int t = upper_bound(ve.begin(), ve.end(), r) - ve.begin();
    temp.push_back()
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