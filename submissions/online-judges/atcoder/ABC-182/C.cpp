#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  string s;
  cin >> s;
  int len = (int) s.length();
  int tot = 0;
  vector<int> cnt(3);
  for (auto& c : s) {
    tot += (c - '0');
    cnt[(c - '0') % 3]++;
  }
  int ans = -1;
  if (tot % 3 == 0) {
    ans = 0;
  } else if (tot % 3 == 1) {
    if (cnt[1] >= 1 && len > 1) ans = 1;
    else if (len > 2) ans = 2;
  } else if (tot % 3 == 2) {
    if (cnt[2] >= 1 && len > 1) ans = 1;
    else if (len > 2) ans = 2;
  }
  cout << ans << '\n';
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