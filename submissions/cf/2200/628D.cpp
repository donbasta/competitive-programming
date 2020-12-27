#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int SZ = 2e3;

int m, d, sz;
string a, b;
ll dp[SZ][2][SZ];
ll ppow[SZ];

ll sub(ll a, ll b) {
  ll ret = a - b;
  ret %= m;
  if(ret < 0) ret += m;
  return ret;
}

ll get(string num) {
  ll ret = 0, cur = 0;
  for(int i = 0; i < sz - 1; i++) {
    int dig = num[i] - '0';
    for(int j = 0; j < dig; j++) {
      if(j == d && !(i & 1)) continue;
      if(j != d && (i & 1)) continue;
      ret += dp[sz - 2 - i][(i & 1) ^ 1][sub(0, cur + 1LL * j * ppow[sz - i - 1])];
      ret %= MOD;
    }
    cur += 1LL * dig * ppow[sz - 1 - i];
    cur %= m;
  }
  for(int i = 0; i <= num[sz - 1] - '0'; i++) {
    if()
  }
  if(cur == 0 && !((sz & 1) && (num[sz - 1] - '0' == d))) ret++;
  ret %= MOD;
  if(ret < 0) ret += MOD;
  return ret;
}

void solve() {

  cin >> m >> d;
  cin >> a >> b;
  sz = a.length();

  ppow[0] = 1;
  for(int i = 1; i < SZ; i++) {
    ppow[i] = (1LL * 10 * ppow[i - 1]) % m;
  }

  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 10; j++) {
      if(i == 0 && j == d) continue;
      dp[0][i][j % m]++;
    }
  }
  for(int i = 1; i < sz; i++) {
    for(int j = 0; j < 2; j++) {
      for(int k = 0; k < m; k++) {
        for(int l = 0; l < 10; l++) {
          if(j == 0 && l == d) continue;
          if(j == 1 && l != d) continue;
          dp[i][j][k] += dp[i - 1][j ^ 1][sub(k, l * ppow[i])];
        }
      }
    }
  }
  ll A, B;
  B = get(b), A = get(a);
  cerr << B << ' ' << A << '\n';
  ll ans = (B - A) % MOD;
  if(ans < 0) ans += MOD;
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