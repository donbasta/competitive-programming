#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e6;
const ll MOD = 1e9 + 7;

int cnt[N + 10];
vector<int> di;
int dp[N + 10], pw2[N + 10], ar[N + 10];
int ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  pw2[0] = 1;
  for(int i = 1; i <= N; i++)
    pw2[i] = (1LL * pw2[i - 1] * 2) % MOD;

  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
    for(int j = 1; j * j <= ar[i]; j++) {
      if(ar[i] % j == 0) {
        di.push_back(j);
        cnt[j]++;
        if(j != ar[i] / j){
          cnt[ar[i] / j]++;
          di.push_back(ar[i] / j);
        }
      }
    }
  }
  sort(di.begin(), di.end());
  di.resize(unique(di.begin(), di.end()) - di.begin());
  int sz = (int)di.size();
  for(int i = sz - 1; i >= 0; i--) {
    int cur = di[i];
    int pw = (1LL * pw2[cnt[cur] - 1] * cnt[cur]) % MOD;
    for(int k = 2; k * cur <= N; k++) {
      pw = (1LL * pw - dp[k * cur]) % MOD;
    }
    dp[cur] = pw;
  }
  for(int i = 2; i <= N; i++) {
    ans = (1LL * ans + 1LL * i * dp[i]) % MOD;
  }
  ans %= MOD;
  if(ans < 0)
    ans += MOD;
  cout << ans << '\n';
  return 0;
}
