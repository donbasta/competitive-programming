#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9 + 7;

int n;

vector<int> digits(int x) {
  vector<int> ret;
  while(x) {
    ret.push_back(x % 10);
    x /= 10;
  }
  return ret;
}

void solve() {
  cin >> n;
  vector<int> ans(n + 1, INF);
  ans[0] = 0;
  for(int i = 1; i <= n; i++) {
    vector<int> dig = digits(i);
    for(auto& e : dig) {
      if(e == 0) continue;
      int prev = i - e;
      ans[i] = min(ans[prev] + 1, ans[i]);
    }
  }
  cout << ans[n] << '\n';
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