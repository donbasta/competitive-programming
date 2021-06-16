#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  int cur = 1;
  int ans = 0;
  while(cur < n && s[cur] == s[0])
    ++cur;
  if(cur == n) {
    ans = (n + 2) / 3;
    cout << ans << '\n';
    return;
  }
  int tot = 1;
  int curLen = 1;
  char last = s[cur];
  cur = (cur + 1) % n;
  while(tot < n) {
    // cerr << cur << ' ' << ans << '\n';
    if(s[cur] == last) {
      curLen++;
    } else {
      ans += (curLen / 3);
      curLen = 1;
      last = s[cur];
    }
    cur = (cur + 1) % n;
    tot++;
  }
  ans += (curLen / 3);
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