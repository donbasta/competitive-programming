#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e3;

ll n, m, k, p;
ll hori[N + 5], ver[N + 5];
ll ar[N + 5][N + 5];

void solve() {
  cin >> n >> m >> k >> p;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> ar[i][j];
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      hori[i] += ar[i][j];
    }
  }
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      ver[i] += ar[j][i];
    }
  }
  priority_queue<pair<ll, int>> pq;
  for(int i = 0; i < m; i++) { pq.emplace(ver[i], 1); }
  for(int i = 0; i < n; i++) { pq.emplace(hori[i] - p, 0); }
  int cur = k;
  ll ans = 0;
  while(cur--) {
    auto now = pq.top();
    pq.pop();
    ans += now.first;
    if(now.second) { now.first -= n * p; }
    else { now.first -= m * p; }
    pq.emplace(now);
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