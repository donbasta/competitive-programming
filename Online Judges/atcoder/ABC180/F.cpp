#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9+7;
const int N = 300;

ll dp[N+5][N+5];
ll fc[N+5], ifc[N+5];
int n, m, l;

ll fe(ll a, ll b) {
  ll ret = 1;
  while(b) {
    if(b&1) ret = ret*a % MOD;
    a = a*a % MOD;
    b >>= 1;
  }
  return ret;
}

ll C(ll a, ll b) {
  if (a<b || a<0 || b<0) return 0;
  ll ret = fc[a];
  ret = (((ret*ifc[a-b]) % MOD)*ifc[b]) % MOD;
  return ret;
}

void init() {
  fc[0] = 1;
  for(int i = 1; i <= N; i++) {
    fc[i] = (fc[i-1] * i) % MOD;
  }
  ifc[N] = fe(fc[N], MOD-2);
  for(int i = N-1; i >= 0; i--) {
    ifc[i] = (ifc[i+1] * (i+1)) % MOD;
  }
}

inline void add(ll& x, ll y) { x = (x+y) % MOD; }

void solve() {
  init();

  cin >> n >> m >> l;
  dp[0][0] = 1;
  dp[1][0] = 1;
  dp[2][0] = 1;
  dp[2][1] = 1;
  dp[2][2] = 1;
  for(int i = 3; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      ll tmp = 0;
      tmp += dp[i-1][j];
      for(int k = 2; k <= i; k++) {
        if(i>=k && j>=k-1)
          add(tmp, ((dp[i-k][j-k+1]*C(i-1, k-1) % MOD)*fc[k] % MOD)*ifc[2] % MOD);
        if(i>=k && j>=k){
          ll lul = ifc[2];
          if(k == 2) lul = 1;
          add(tmp, ((dp[i-k][j-k]*C(i-1, k-1) % MOD)*fc[k-1] % MOD)*lul % MOD);
        }
      }
      dp[i][j] = tmp;
    }
  }
  // for(int i = 2; i <= n; i++) {
  //   for(int j = 1; j <= m; j++) {
  //     cerr << i << ' ' << j << ' ' << dp[i][j] << '\n';
  //   }
  // }
  for(int i = 2; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      
    }
  }
  cout << dp[n][m] << '\n';
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