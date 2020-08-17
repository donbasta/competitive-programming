#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e6;
const int MOD = 1e9 + 7;

int fc[N + 5], ifc[N + 5];
int cnt[26];

int fastexp(int a, int b) {
  int ret = 1;
  while(b) {
    if(b & 1) ret = 1LL * ret * a % MOD;
    a = 1LL * a * a % MOD;
    b >>= 1;
  }
  return ret;
}

int inv(int a) {
  return fastexp(a, MOD - 2);
}

void init() {
  fc[0] = 1;
  for(int i = 1; i <= N; i++) {
    fc[i] = 1LL * i * fc[i - 1] % MOD;
  }
  ifc[N] = inv(fc[N]);
  for(int i = N - 1; i >= 0; i--) {
    ifc[i] = 1LL * (i + 1) * ifc[i + 1] % MOD;
  }
}

void solve() {
  string s;
  cin >> s;
  int n = (int)s.length();
  for(int i = 0; i < n; i++) {
    int cur = s[i] - 'a';
    cnt[cur]++;
  }
  int ret = fc[n];
  for(int i = 0; i < 26; i++) {
    ret = 1LL * ret * ifc[cnt[i]] % MOD;
  }
  cout << ret << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  init();
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}