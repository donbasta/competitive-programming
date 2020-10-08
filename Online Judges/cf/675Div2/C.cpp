#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;

inline ll C2(ll a) { return (a * (a - 1) / 2) % MOD; }

void solve() {
  string s;
  cin >> s;
  int n = (int) s.length();
  ll tmp = s[0] - '0', ans = 0, pre = tmp;
  for(int i = 1; i < n; i++) {
    int dig = s[i] - '0';
    ans = (ans * 10 + dig * C2(i + 1) + pre) % MOD;
    tmp = (tmp * 10 + dig) % MOD;
    pre = (pre + tmp) % MOD;
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