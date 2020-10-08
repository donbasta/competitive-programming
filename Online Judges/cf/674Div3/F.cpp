#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int fastexpo(int a, int b) {
  if(b < 0) return 0;
  int ret = 1;
  while(b) {
    if(b & 1) ret = (1LL * ret * a) % MOD;
    a = (1LL * a * a) % MOD;
    b >>= 1;
  }
  return ret;
}

inline int add(int x, int y) { return (1LL * x + y) % MOD; }

void solve() {
  int n;
  string s;
  cin >> n >> s;
  int tot = 0;

  vector<vector<int>> pre(2, vector<int>(n + 5)), suf(2, vector<int>(n + 5));

  for(int i = 0; i < n; i++) {
    int ni = i + 1;
    pre[0][ni] = pre[0][ni - 1] + (s[i] == 'a');
    pre[1][ni] = pre[1][ni - 1] + (s[i] == '?');
    tot += (s[i] == '?');
  }
  for(int i = n - 1; i >= 0; i--) {
    int ni = i + 1;
    suf[0][ni] = suf[0][ni + 1] + (s[i] == 'c');
    suf[1][ni] = suf[1][ni + 1] + (s[i] == '?');
  }

  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'a' || s[i] == 'c')
      continue;
    int ntot = tot - (s[i] == '?');
    int ni = i + 1;
    int ap, aq, cp, cq;
    ap = pre[0][ni - 1], aq = pre[1][ni - 1];
    cp = suf[0][ni + 1], cq = suf[1][ni + 1];
    ans = add(ans, ((1LL * ap * cp) % MOD * fastexpo(3, ntot)) % MOD);
    ans = add(ans, ((1LL * ap * cq) % MOD * fastexpo(3, ntot - 1)) % MOD);
    ans = add(ans, ((1LL * aq * cp) % MOD * fastexpo(3, ntot - 1)) % MOD);
    ans = add(ans, ((1LL * aq * cq) % MOD * fastexpo(3, ntot - 2)) % MOD);
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