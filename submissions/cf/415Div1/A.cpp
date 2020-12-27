#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;

int n;
vector<int> ve;
ll ans;

ll pw(ll a, ll b) {
  ll ret = 1;
  while(b) {
    if(b & 1) {ret = ret * a % MOD;}
    a = a * a % MOD;
    b >>= 1;
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n;
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    ve.push_back(x);
  }
  sort(ve.begin(), ve.end());
  for(int i = 0; i < n; i++) {
    ll temp = pw(2, i) - pw(2, n - i - 1);
    temp = ((temp % MOD) + MOD) % MOD;
    ans += 1LL * ve[i] * temp;
    ans %= MOD;
  }
  cout << ans << '\n';
  return 0;
}
