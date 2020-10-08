#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, m;
  cin >> n >> m;
  multiset<int> se;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    se.insert(x);
  }
  for(int i = 0; i < m; i++) {
    int cost;
    cin >> cost;
    if(se.empty()) {
      cout << -1 << '\n';
    } else {
      auto it = se.lower_bound(cost);
      if(it == se.begin() && *it > cost) {
        cout << -1 << '\n';
        continue;
      } else if(it == se.end() || *it > cost) {
        --it;
        cout << *it << '\n';
        se.erase(it);
      } else if(*it == cost) {
        cout << *it << '\n';
        se.erase(it);
      } 
    }
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