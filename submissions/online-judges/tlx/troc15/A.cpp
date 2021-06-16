#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

void solve() {
  ll a, b;
  cin >> a >> b;
  if (b % a != 0) {
    cout << "-1 -1\n";
    return;
  }
  ll da = b / a;
  pair<ll, ll> ans = make_pair(a, a*da);
  ll cur = a + a*da;
  for (ll i = 1; i * i <= da; i++) {
    if (da % i == 0) {
      if (cur > a*i, a*(da/i) && __gcd(i, da/i) == 1){
        cur = a*i + a*(da/i);
        ans = make_pair(a*i, a*(da/i));
      }
    }
  }
  cout << ans.first << ' ' << ans.second << '\n';
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