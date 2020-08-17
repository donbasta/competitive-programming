#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<int> ve;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ve.emplace_back(x);
  }
  multiset<int> se;
  for(int i = 0; i < n; i++) {
    if(se.empty()) {se.emplace(ve[i]); continue;}
    auto next = se.upper_bound(ve[i]);
    if(next == se.end()) {
      se.emplace(ve[i]);
      continue;
    }
    se.erase(next);
    se.insert(ve[i]);
  }
  cout << (int)se.size() << '\n';
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