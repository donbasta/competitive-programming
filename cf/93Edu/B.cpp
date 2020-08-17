#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  string s;
  cin >> s;
  int n = (int)s.length();
  int last = -1;
  int cur = 0;
  vector<int> ve;
  for(int i = 0; i < n; i++) {
    int now = s[i] - '0';
    if(now == last) cur++;
    else {
      if(last == 1) {ve.push_back(cur);}
      last = now;
      cur = 1;
    }
  }
  if(last == 1) {ve.push_back(cur);}
  sort(ve.begin(), ve.end(), greater<int>());
  int sz = (int)ve.size();
  int ans = 0;
  for(int i = 0; i < sz; i += 2) {
    ans += ve[i];
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