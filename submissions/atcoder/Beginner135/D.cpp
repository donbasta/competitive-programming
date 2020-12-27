#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;

inline void add(int& x, int y) { x = (1LL * x + y) % MOD; }

int fastexpo(int a, int b, int mod) {
  int ret = 1;
  while(b) {
    if(b & 1) { ret = 1LL * ret * a % mod; }
    a = 1LL * a * a % mod;
    b >>= 1;
  }
  return ret;
}

void solve() {
  string s;
  cin >> s;
  int n = (int)s.length();

  vector<int> ve;
  vector<vector<int>> dp(n + 1, vector<int>(13));
  int sum = 0;
  for(int i = 0; i < n; i++) {
    int pang = n - 1 - i;
    int pw = fastexpo(10, pang, 13);
    if(s[i] == '?') {  
      ve.push_back(pw);
    } else {
      int dig = (s[i] - '0');
      sum = (1LL * sum + pw * dig) % 13;
    }
  }
  int need = (5 - sum) % 13;
  if(need < 0) need += 13;

  if(ve.empty()) {
    if(need == 0) { cout << 1 << '\n'; }
    else { cout << 0 << '\n'; }
    return;
  }

  int sz = (int)ve.size();
  for(int i = 0; i < 10; i++) {
    int val = (i * ve[0]) % 13;
    dp[0][val]++;
  }
  for(int i = 1; i < sz; i++) {
    for(int j = 0; j < 10; j++) {
      int val = (j * ve[i]) % 13;
      for(int k = 0; k < 13; k++) {
        add(dp[i][(val + k) % 13], dp[i - 1][k]);
      }
    }
  }
  cout << dp[sz - 1][need] << '\n';
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