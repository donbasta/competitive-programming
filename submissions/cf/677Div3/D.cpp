#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<int> ar(n + 1);
  set<int> se;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
    se.insert(ar[i]);
  }
  if((int)se.size() == 1) {
    cout << "NO" << '\n';
    return;
  }
  cout << "YES" << '\n';
  // vector<int> pos(1, 1);
  vector<bool> nope(n + 1, 0);
  int beda = 0;
  for(int i = 2; i <= n; i++) {
    if(ar[i] == ar[1]) {
      // pos.push_back(i);
      nope[i] = 1;
    } else {
      beda = i;
    }
  }
  assert(beda != 0);
  vector<pair<int, int>> edge;
  for(int i = 2; i <= n; i++) {
    if(!nope[i])
      edge.emplace_back(1, i);
    else
      edge.emplace_back(beda, i);
  }
  assert((int)edge.size() == n - 1);
  for(auto& e : edge) {
    cout << e.first << ' ' << e.second << '\n';
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