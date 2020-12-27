#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const pair<ll, ll> ORIGIN = make_pair(0LL, 0LL);

ll dobelArea(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c = ORIGIN) {
  ll ret = a.first * b.second + b.first * c.second + c.first * a.second;
  ret -= (a.second * b.first + b.second * c.first + c.second * a.first);
  return ret; 
}

void solve() {
  int n;
  vector<pair<ll, ll>> pt;
  cin >> n;
  for(int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    pt.emplace_back(x, y);
  }
  ll dobelLuas = 0;
  for(int i = 0; i < n; i++) {
    int next = (i + 1) % n;
    dobelLuas += dobelArea(pt[i], pt[next]);
  }
  dobelLuas = abs(dobelLuas);
  ld Luas = ((ld) (dobelLuas)) / 2.0;
  cout << fixed << setprecision(1);
  cout << Luas << '\n';
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