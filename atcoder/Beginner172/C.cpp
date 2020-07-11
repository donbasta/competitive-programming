#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int INF = 1e9;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> a(n + 1), b(m + 1), pa(n + 1, 0), pb(m + 1, 0);
  for(int i = 0; i < n; i++) {
    cin >> a[i + 1];
    pa[i + 1] = pa[i] + a[i + 1];
  }
  for(int j = 0; j < m; j++) {
    cin >> b[j + 1];
    pb[j + 1] = pb[j] + b[j + 1];
  }
  int ans = -INF;
  for(int i = 0; i <= n; i++) {
    ll temp = pa[i];
    ll sisa = k - temp;
    if(sisa < 0)
      break;
    int lul = upper_bound(pb.begin(), pb.end(), sisa) - pb.begin();
    // cerr << i << ' ' << lul - 1 << '\n';
    ans = max(ans, lul - 1 + i);
  }
  cout << ans << '\n';
  return 0;
}
