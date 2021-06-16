#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int n;
  cin >> n;
  vector<pair<int, int>> ve;

  for(int i = 0; i <= 2 * (n + 1); i++) {
    ve.emplace_back(2, i);
  }
  for(int i = 0; i <= 2 * n; i += 4) {
    ve.emplace_back(1, i);
    ve.emplace_back(1, i + 2);
    ve.emplace_back(0, i);
    ve.emplace_back(0, i + 1);
    ve.emplace_back(0, i + 2);
  }
  for(int i = 2; i <= 2 * n; i += 4) {
    ve.emplace_back(3, i);
    ve.emplace_back(3, i + 2);
    ve.emplace_back(4, i);
    ve.emplace_back(4, i + 1);
    ve.emplace_back(4, i + 2);
  }
  cout << (int)ve.size() << '\n';
  for(auto i : ve) {
    cout << i.first << ' ' << i.second << '\n';
  }
  return 0;
}
