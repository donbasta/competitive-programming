#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

map<char, int> mp;
string lol = "RSP";

void solve() {
  string s;
  cin >> s;
  int len = (int)s.length();
  vector<int> cnt(3, 0);
  for(auto i : s) {
    cnt[mp[i]]++;
  }
  int mx = 0, idx = -1;
  for(int i = 0; i < 3; i++) {
    if(mx < cnt[i]) {
      mx = cnt[i], idx = i;
    }
  }
  idx = (idx + 2) % 3;
  string ans(len, lol[idx]);
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  mp['R'] = 0, mp['S'] = 1, mp['P'] = 2;

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  
  return 0;
}