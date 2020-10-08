#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
  cin >> n;
  vector<int> ve;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ve.push_back(x);
  }
  sort(ve.begin(), ve.end());
  ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
  bool ok = true;
  for(int i = 0; i < (int)ve.size() - 1; i++) {
    ok &= ((ve[i + 1] - ve[i]) <= 1);
  }
  cout << (ok ? "YES" : "NO") << '\n';
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