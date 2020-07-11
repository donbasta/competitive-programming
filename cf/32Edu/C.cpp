#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

string s;
vector<int> ve[26];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> s;
  int sz = (int)s.length();
  for(int i = 0; i < 26; i++) {
    ve[i].push_back(0);
  }
  for(int i = 0; i < sz; i++) {
    ve[s[i] - 'a'].push_back(i + 1);
  }
  for(int i = 0; i < 26; i++) {
    ve[i].push_back(sz + 1);
  }
  int ans = 1e9;
  for(int i = 0; i < 26; i++) {
    int mx = ve[i][1] - ve[i][0];
    for(int j = 1; j < (int)ve[i].size(); j++) {
      mx = max(mx, ve[i][j] - ve[i][j - 1]);
    }
    ans = min(mx, ans);
  }
  cout << ans << '\n';
  return 0;
}
