#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, a, b;

ll f(ll x, ll k) {
  ll ceil = (x - k * b + a - b - 1) / (a - b);
  return max(0LL, ceil);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> a >> b;
  vector<int> h(n);
  for(int i = 0; i < n; i++) {
    cin >> h[i];
  }
  int hi = 1e9, lo = 1, ans = -1;
  while(hi >= lo) {
    ll mid = (hi + lo) / 2;
    ll temp = 0;
    for(int i = 0; i < n; i++) {
      temp += f(h[i], mid);
    }
    if(mid >= temp) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  cout << ans << '\n';
  return 0;
}