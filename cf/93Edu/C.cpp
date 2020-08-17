#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<int> pre(n + 1);
  map<int, int> mp;
  mp[0] = 1;
  string s;
  cin >> s;
  for(int i = 1; i <= n; i++) {
    int x = s[i - 1] - '0';
    pre[i] = pre[i - 1] + x;
    mp[pre[i] - i]++;
  }
  ll ans = 0;
  for(auto i : mp) {
    int cnt = i.second;
    ans += 1LL * cnt * (cnt - 1) / 2;
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