#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 3e5;
const ll MOD = 998244353;

ll fc[N + 5], ifc[N + 5];

ll fastexpo(ll a, ll b) {
  ll ret = 1;
  while(b) {
    if(b & 1) { ret = (ret * a) % MOD; }
    a = (a * a) % MOD;
    b >>= 1;
  }
  return ret;
}

ll inv(ll a) {
  return fastexpo(a, MOD - 2);
}

void init_fac() {
  fc[0] = 1;
  for(int i = 1; i <= N; i++) {
    fc[i] = fc[i - 1] * i % MOD;
  }
  ifc[N] = inv(fc[N]);
  for(int i = N - 1; i >= 0; i--) {
    ifc[i] = ifc[i + 1] * (i + 1) % MOD;
  }
}

ll C(ll a, ll b) {
  if(a < b || a < 0 || b < 0) return 0;
  ll ret = fc[a];
  ret = ret * ifc[b] % MOD;
  ret = ret * ifc[a - b] % MOD;
  return ret;
}

int n, k;
pair<int, int> ti[N + 5];

void solve() {

  init_fac();

  cin >> n >> k;

  vector<int> ve;
  for(int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    ti[i] = make_pair(x, y);
    ve.emplace_back(x), ve.emplace_back(y);
  }
  sort(ve.begin(), ve.end());
  ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
  int cnt = 0;

  map<int, int> mp;
  for(auto i : ve) {
    mp[i] = cnt++;
  }

  vector<int> a(2 * n + 1), b(2 * n + 1);
  for(int i = 1; i <= n; i++) {
    a[mp[ti[i].first]]++;
    b[mp[ti[i].second]]++;
  }

  ll ans = 0;
  int cur = 0;
  for(auto i : ve) {
    ans = (ans + C(cur + a[mp[i]], k) - C(cur, k)) % MOD;
    cur += a[mp[i]];
    cur -= b[mp[i]];
  }
  if(ans < 0) ans += MOD;
  cout << ans << '\n';
  return;
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