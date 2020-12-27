#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

bool inside(int a, int b, int c) {
  if (b > c) swap(b, c);
  return (b <= a && a <= c);
}

void solve() {
  int n;
  cin >> n;
  vector<ll> t(n + 5), x(n + 5);
  t[n + 1] = INF;
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> x[i];
  }
  ll curPos = 0;
  ll departTime = 0;
  ll arriveTime = 0;
  int cnt = 0;
  int dir = 0;
  pair<ll, ll> route = make_pair(0, 0);
  for (int i = 1; i <= n; i++) {
    if (arriveTime > t[i]) {
      if (arriveTime <= t[i + 1]) {
        if (inside(x[i], route.first + dir * (t[i] - departTime), route.second)) {
          cnt++;
          // cerr << i << '\n';
        }
      } else {
        if (inside(x[i], route.first + dir * (t[i] - departTime), route.first + dir * (t[i + 1] - departTime))) {
          cnt++;
          // cerr << i << '\n';
        }
      }
      continue;
    }
    curPos = route.second;
    departTime = t[i];
    arriveTime = t[i] + abs(curPos - x[i]);
    route = make_pair(curPos, x[i]);
    if (curPos <= x[i]) dir = 1;
    else dir = -1;
    if (arriveTime <= t[i + 1]) {
      cnt++;
      // cerr << i << '\n';
    }
  }
  cout << cnt << '\n';
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