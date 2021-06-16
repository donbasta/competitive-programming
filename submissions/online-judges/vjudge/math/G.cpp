#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const int N = 2e3;

int n;
ll fac[N + 5], ifac[N + 5], pre[N + 5][N + 5], inve[N + 5];
int nx[N + 5], pr[N + 5];

ll fastexpo(ll a, ll b) {
  ll res = 1;
  while(b) {
    if(b & 1) { res = (res * a) % MOD; }
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

ll inv(ll a) {
  return fastexpo(a, MOD - 2);
}

ll C(ll a, ll b) {
  if(a < b || a < 0 || b < 0) return 0;
  ll ret = fac[a];
  ret = ret * ifac[b] % MOD;
  ret = ret * ifac[a - b] % MOD;
  return ret;
}

void init() {
  pre[0][0] = 1;
  for(int i = 1; i <= n; i++) { pre[0][i] = 0; }
  for(int i = 1; i <= n; i++) {
    pre[i][0] = 0;
    for(int j = 1; j <= i; j++) {
      pre[i][j] = (pre[i - 1][j] * (i - 1) + pre[i - 1][j - 1]) % MOD;
    }
  }
  fill(pr, pr + n + 1, -1);
  fill(nx, nx + n + 1, -1);
}

void init_fac() {
  fac[0] = 1;
  for(int i = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * i % MOD;
  }
  ifac[n] = inv(fac[n]);
  for(int i = n - 1; i >= 0; i--) {
    ifac[i] = ifac[i + 1] * (i + 1) % MOD;
  }
}

void solve() {
  cin >> n;
  init();
  init_fac();
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if(x == -1) continue;
    nx[i] = x;
    pr[x] = i;
  }
  int alone = 0, together = 0;
  for(int i = 1; i <= n; i++) {
    if(pr[i] != -1) continue;
    int cur = i;
    int len = 1;
    bool ok = 1;
    while(1) {
      cur = nx[cur];
      if(cur == -1) break;
      if(cur == i) { ok = 0; break; }
      len++;
    }
    if(ok) {
      if(len == 1) alone++;
      else together++;
    }
  }
  ll comp = alone + together;
  ll ans = 0;
  for(int i = 0; i <= alone; i++) {
    ll temp = 0;
    for(int j = 0; j <= comp - i; j++) {
      temp = (temp + pre[comp - i][j]) % MOD;
    }
    temp = temp * C(alone, i) % MOD;
    if(i & 1) ans = (ans - temp) % MOD;
    else ans = (ans + temp) % MOD;
  }
  ans %= MOD;
  if(ans < 0) ans += MOD;
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  for(int i = 1; i <= TC; i++) {
    clock_t start = clock();
    solve();
    cerr << fixed << setprecision(20) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
  }
  
  
  return 0;
}