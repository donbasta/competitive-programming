#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, k;
  cin >> n >> k;

  set<int> se;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    se.insert(x);
  }
  if(k == 1 && (int)se.size() > 1) {
    cout << -1 << '\n';
    return;
  }
  if(k == 1 && (int)se.size() == 1) {
    cout << 1 << '\n';
    return;
  }
  int tot = (int)se.size();
  tot--;
  // cerr << tot << '\n';
  cout << (tot + k - 2) / (k - 1) << '\n';
  return;
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