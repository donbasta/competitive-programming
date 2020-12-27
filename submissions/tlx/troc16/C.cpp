#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll mod = 1e9 + 7;
const int N = 1e3;

ll f[N + 5];

ll fpow(ll a, ll b) {
  ll ret = 1;
  while(b) {
    if (b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}

void solve() {
  int n, m;
  cin >> n >> m;
  f[1] = 1LL; 
  f[2] = 2LL * (m - 1);
  for (int i = 3; i <= n; i++) {
    f[i] = 1LL * (m - 1) * (f[i - 1] + f[i - 2]) % mod;
    f[i] = (f[i] + fpow(m - 1, i - 1)) % mod;
  }
  cout << f[n] << '\n';
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