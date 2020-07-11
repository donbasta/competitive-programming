#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
const ll MAX = 1e6;

ll cube(ll x) {
  return x * x * x;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll m;
  cin >> m;
  ll cur = 1;
  ll sum = 0;
  vector<ll> ve;
  vector<ll> pre;
  while(sum < m) {
    ll now = cube(cur);
    ll next = cube(cur + 1);
    ll temp = 0;
    while(sum + now < next && sum + now <= m) {
      sum += now;
      ve.push_back(cur);
      pre.push_back(sum);
    }
    cur++;
    if(sum + now >= m)
      break;
  }
  cerr << sum << " :)\n";
  int sz = (int) ve.size();
  ve.push_back(MAX);
  cerr << "lol";
  for(int i = sz - 1; i >= 0; i--) {
    ll temp = ve[i];
    while(temp < ve[i + 1] && sum - cube(temp) + cube(temp + 1) <= m) {
      bool ok = true;
      for(int j = i + 1; j < sz; j++) {
        ok &= (pre[j] - cube(temp) + cube(temp + 1) < cube(ve[j] + 1));
      }
      if(!ok)
        break;
      sum = sum - cube(temp) + cube(temp + 1);
      for(int j = i; j < sz; j++) {
        pre[j] = pre[j] - cube(temp) + cube(temp + 1);
      }
      temp++;
    }
    ve[i] = temp;
  }
  cout << sz << ' ' << sum << '\n';
  return 0;
}
