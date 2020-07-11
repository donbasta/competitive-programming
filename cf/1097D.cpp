#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;

ll n;
int k;
vector<pair<int, ll>> di;
ll ans = 1;
 
vector<pair<int, ll>> factors(ll x) {
  vector<pair<int, ll>> pr;
  ll temp = x;
  for(ll i = 2; i * i <= temp; i++) {
    if(temp % i == 0) {
      int cnt = 0;
      while(temp % i == 0) {
        cnt++;
        temp /= i;
      }
      pr.emplace_back(cnt, i);
    }
  }
  if(temp > 1)
    pr.emplace_back(1, temp);
  return pr;
}

int modpow(int a, int b) {
  int ret = 1;
  while(b) {
    if(b & 1) ret = (1LL * ret * a) % MOD;
    a = (1LL * a * a) % MOD; 
    b >>= 1;
  }
  return ret;
}

int inv(int x) {
  return modpow(x, MOD - 2);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;
  di = factors(n);
  for(auto i : di) {
    int cnt = i.first;
    ll prima = i.second;
    vector<int> dp[2];
    for(int j = 0; j < 2; j++) 
      dp[j].resize(cnt + 1);
    ll temp = 1;
    for(int j = 0; j <= cnt; j++) {
      dp[0][j] = temp % MOD;
      temp = (temp * prima) % MOD;
    }
    for(int j = 1; j <= k; j++) {
      int now = j & 1;
      int prev = now ^ 1;
      for(int l = 0; l <= cnt; l++) {
        dp[now][l] = 0;
        for(int m = 0; m <= l; m++) {
          dp[now][l] = (1LL * dp[now][l] + dp[prev][m]) % MOD;
        }
        dp[now][l] = (1LL * dp[now][l] * inv(l + 1)) % MOD;
        // cerr << j << ' ' << l << ' ' << dp[now][l] << '\n';
      }
    }
    ans = (ans * dp[k & 1][cnt]) % MOD;
  }
  if(ans < 0)
    ans += MOD;
  cout << ans << '\n';
  return 0;
}
