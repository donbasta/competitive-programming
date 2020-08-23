#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

string s;

void solve() {
  cin >> s;
  int sz = (int)s.length();
  vector<int> ve(sz);
  for(int j = 0; j < sz; j++) ve[j] = s[j] - '0';
  int ans = 1;
  for(int i = sz; i >= 2; i--) {
    bool flag = false;
    for(int dig = 0; dig < 10; dig++) {
      vector<int> temp = ve;
      vector<int> cnt(sz);
      int now = 0;
      for(int j = 0; j <= sz - i; j++) {
        int need = (dig - now - temp[j]) % 10;
        if(need < 0) need += 10;
        cnt[j] = need;
        now += cnt[j];
        if(j >= i - 1) now -= cnt[j - i + 1];
        now %= 10;
        if(now < 0) now += 10;
      }
      bool ok = true;
      for(int j = sz - i + 1; j < sz; j++) {
        int cur = (temp[j] + now) % 10;
        if(cur < 0) cur += 10;
        ok &= (dig == cur);
        if(j >= i - 1) now = (now - cnt[j - i + 1]);
      }
      if(ok) {flag = true; break;}
    }
    if(flag) {
      ans = i;
      break;
    }
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