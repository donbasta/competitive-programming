#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, m;
  cin >> n >> m;
  set<int> se;
  for (int i = 0; i < n + m; i++) {
    int x;
    cin >> x;
    se.emplace(x);
  }
  int dif = (int)se.size();
  cout << n + m - dif << '\n';
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