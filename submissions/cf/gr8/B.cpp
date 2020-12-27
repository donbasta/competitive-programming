#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

string s = "codeforces";

ll pow10(ll x) {
  ll res = 1;
  for(int i = 1; i <= 10; i++) {
    res *= x;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  ll k, pos;
  cin >> k;
  for(ll i = 1; i <= 41; i++) {
    if(pow10(i) >= k) {
      pos = i - 1;
      break;
    }
  }
  if(pos == 0) {
    cout << "codeforces" << '\n';
    return 0;
  }
  ll temp = pow10(pos);
  int cnt = 0;
  for(int i = 1; i <= 10; i++) {
    temp = temp * (pos + 1) / pos;
    if(temp >= k) {
      cnt = i;
      break;
    }
  }
  string ans = "";
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < pos; j++) {
      ans += s[i];
    }
    if(cnt) {
      ans += s[i];
      cnt--;
    }
  }
  cout << ans << '\n';
  return 0;
}
