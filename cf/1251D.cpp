#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;
ll s;
vector<pair<ll, ll>> ve;

bool cek(ll bat) {
  ll sum = 0;
  vector<int> idx;
  int a = 0, b = 0, c = 0;
  for(int i = 0; i < n; i++) {
    if(ve[i].second < bat) {
      a++; sum += ve[i].first;
    } else if(ve[i].first > bat) {
      c++; sum += ve[i].first;
    } else {
      b++; idx.push_back(i);
    }
  }
  if(a > (n / 2) || c > (n / 2)) {
    return false;
  }
  for(auto i : idx) {
    if(a < (n / 2)) {
      sum += ve[i].first;
      a++;
    } else {
      sum += bat;
    }
  }
  return (sum <= s);
}

void solve() {
  cin >> n >> s;
  ve.clear();
  for(int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    ve.emplace_back(x, y);
  }
  sort(ve.begin(), ve.end());
  ll lo = ve[n / 2].first, hi = 2e9;
  ll ans = -1;
  while(lo <= hi) {
    ll mid = (lo + hi) / 2;
    if(cek(mid)) {
      ans = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
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