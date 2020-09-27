#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9 + 7;

void solve() {
  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    se.insert(x);
    ve.emplace_back(x);
  }
  sort(ve.begin(), ve.end());
  se.insert(0), se.insert(INF);
  for(int i = 1; i < n; i++) {
    int sel = ve[i] - ve[i - 1];
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