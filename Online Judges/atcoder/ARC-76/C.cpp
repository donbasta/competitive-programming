#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e5;

int fact[N + 69];
int n, m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  fact[0] = 1;
  for(int i = 1; i <= N; i++) {
    fact[i] = (1LL * fact[i - 1] * i) % MOD;
  }

  cin >> n >> m;
  int ans = 1;
  ans = (1LL * ans * fact[n]) % MOD;
  ans = (1LL * ans * fact[m]) % MOD;

  if(abs(n - m) > 1) {
    ans = 0;
  } else if(n == m) {
    ans = (1LL * ans * 2) % MOD;
  }

  cout << ans << '\n';
  
  return 0;
}