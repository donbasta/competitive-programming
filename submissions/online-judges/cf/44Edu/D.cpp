#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll n, h;

inline ll f(ll x) {
  return x * (x+1) / 2;
}

inline ll g(ll x) {
  return x*x - f(h-1);
}

void solve() {
  cin >> n >> h;

  ll l = 0, r = 2e9;
  while(l < r) {
    ll mid = (l + r + 1) / 2;
    if (f(mid) > n) {
      r = mid-1;
    } else {
      l = mid;
    }
  }
  assert(f(l) <= n && f(l+1) > n);
  ll ans = 0;
  if (l <= h) {
    if (f(l) == n) {
      ans = l;
    } else {
      ans = l + 1;
    }
  } else {
    l = 0, r = 2e9;
    while(l < r) {
      ll mid = (l + r + 1) / 2;
      if (g(mid) > n) {
        r = mid-1;
      } else {
        l = mid;
      }
    }
    assert(g(l) <= n && g(l+1) > n);
    if (g(l) == n) {
      ans = l*2 - h;
    } else {
      ll sisa = n - g(l);
      assert(sisa >= 1 && sisa <= 2*l + 1);
      if (sisa <= l){
        ans = l*2 - h + 1;
      } else {
        ans = l*2 - h + 2;
      }
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