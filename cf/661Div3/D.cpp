#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> last[2];
  vector<int> ans(n);
  int now = 0;
  for(int i = 0; i < n; i++) {
    int cur = s[i] - '0';
    if(last[cur ^ 1].empty()) {
      ans[i] = ++now;
    } else {
      ans[i] = last[cur ^ 1].back();     
      last[cur ^ 1].pop_back();
    }
    last[cur].emplace_back(ans[i]);
  }
  cout << now << '\n';
  for(int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
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