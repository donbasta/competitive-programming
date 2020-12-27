#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;

ll fastexpo(ll a, ll b) {
  ll ret = 1;
  while(b) {
    if(b & 1) { ret = ret * a % MOD; }
    a = a * a % MOD;
    b >>= 1;
  }
  return ret;
}

ll inv(ll a) {
  return fastexpo(a, MOD - 2);
}

int n;
vector<pair<int, int>> ve;

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    ve.emplace_back(y, x);
  }
  sort(ve.begin(), ve.end());
  int r = ve[0].first;
  ll ans = (ve[0].first + ve[0].second) * inv(2) % MOD;

  for(int i = 1; i < n; i++) {
    if(ve[i].second >= r) {
      ans = (ve[i].first + ve[i].second) * inv(2) % MOD;
    } else {
      ll lul = inv(ve[i].first - ve[i].second) % MOD;
      ll p1 = ((ve[i].first - r) * (ve[i].first + r) % MOD) * inv(2) % MOD;
      ll p2 = (r - ve[i].second) * ans % MOD;
      ans = ((p1 + p2) * lul) % MOD;
    }
    r = ve[i].first;
  }
  for(int i = 0; i < n; i++) {
    ans = ans * (ve[i].first - ve[i].second) % MOD;
  }
  for(int i = 1; i <= (n + 1); i++) {
    ans = ans * i % MOD;
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