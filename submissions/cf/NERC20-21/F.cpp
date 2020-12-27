#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
  cin >> n;
  map<pair<ll, ll>, int> cnt; 
  for (int i = 0; i < n; i++) {
    ll x, y, u, v;
    cin >> x >> y >> u >> v;
    ll dy = v - y, dx = u - x;
    ll gcd = abs(__gcd(dx, dy));
    dy /= gcd, dx /= gcd;
    cnt[make_pair(dx, dy)]++;
  }
  ll ans = 0;
  for (auto e : cnt) {
    auto dir = e.first;
    pair<int, int> back = make_pair(-dir.first, -dir.second);
    if (cnt.find(back) == cnt.end()) {
      continue;
    } else {
      ans += 1LL * e.second * cnt[back];
    }
  }
  assert (ans % 2 == 0);
  ans /= 2;
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}