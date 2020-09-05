#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 2e5;

int fastexpo(int a, int b) {
  int ret = 1;
  while(b) {
    if(b & 1) { ret = 1LL * ret * a % MOD; }
    a = 1LL * a * a % MOD;
    b >>= 1;
  }
  return ret;
}

int cnt[N + 5], pre[N + 5], suf[N + 5];
int m;

void solve() {
  cin >> m;
  for(int i = 1; i <= m; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  pre[0] = 1, suf[N + 1] = 1;
  for(int i = 1; i <= N; i++) {
    pre[i] = 1LL * pre[i - 1] * (cnt[i] + 1) % (MOD - 1);
  }
  for(int i = N; i >= 1; i--) {
    suf[i] = 1LL * suf[i + 1] * (cnt[i] + 1) % (MOD - 1);
  }
  int ans = 1;
  for(int i = 1; i <= N; i++) {
    if(cnt[i] == 0) continue;
    int temp = 1LL * pre[i - 1] * suf[i + 1] % (MOD - 1);
    int cur = (1LL * cnt[i] * (cnt[i] + 1) / 2) % (MOD - 1);
    temp = 1LL * temp * cur % (MOD - 1);
    ans = 1LL * ans * fastexpo(i, temp) % MOD;
  }
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