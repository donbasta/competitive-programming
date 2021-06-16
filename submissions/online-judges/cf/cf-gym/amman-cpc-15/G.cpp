#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9;

void solve() {
  int n, s;
  cin >> n >> s;
  vector<int> c(n);
  for(int i = 0; i < n; i++) {
    cin >> c[i];
  }
  int ans = 0;
  for(int i = 0; i < (1 << n); i++) {
    int mn = INF;
    int sum = 0, cnt = 0;
    for(int j = 0; j < n; j++) {
      if((i >> j) & 1) {
        cnt++;
        sum += c[j];
        mn = min(mn, c[j]);
      }
    }
    if((sum >= s) && (sum - mn < s))
      ans = max(ans, cnt);
  }
  cout << ans << '\n';
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