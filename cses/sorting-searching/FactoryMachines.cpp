#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

ll n, t;
vector<ll> k;

bool bisa(ll days) {
  ll cek = 0;
  for(int i = 0; i < n; i++) {
    cek += (days / k[i]);
    if(cek >= t) return true;
  }
  return (cek >= t);
}

void solve() {
  cin >> n >> t;
  k.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> k[i];
  }
  ll l = 1, r = INF, ans = -1;
  while(l <= r) {
    ll mid = (l + r) >> 1;
    if(bisa(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
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