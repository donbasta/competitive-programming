#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e5 + 69;

string s;
ll x1, x2, y11, y2, n;
ll hori[N], ver[N];

bool bisa(ll day) {
  ll x, y, hr, vr, dh, dv, sh, sv;
  x = day % n;
  y = day / n;
  hr = hori[n] * y + hori[x];
  vr = ver[n] * y + ver[x];
  sh = abs(x2 - x1 - hr);
  sv = abs(y2 - y11 - vr);
  return (sh + sv <= day);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> x1 >> y11 >> x2 >> y2;
  cin >> n >> s;

  for(int i = 1; i <= n; i++) {
    hori[i] = hori[i - 1];
    ver[i] = ver[i - 1];
    if(s[i - 1] == 'U')
      ver[i]++;
    else if(s[i - 1] == 'D')
      ver[i]--;
    else if(s[i - 1] == 'L')
      hori[i]--;
    else if(s[i - 1] == 'R')
      hori[i]++;
  }

  ll hi = 1e15, lo = 0;
  ll ans = -1;
  while(hi >= lo) {
    ll mid = (hi + lo) / 2;
    if(bisa(mid)) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
