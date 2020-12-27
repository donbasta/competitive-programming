#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define pii pair<int, int>

const int M = 100;
// int d[2 * M + 5];
vector<pii> adj[2 * M + 5];

void solve() {
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  for (int i = 1; i <= 198; i++) {
    adj[i].emplace_back(i + 2, y);
    adj[i + 2].emplace_back(i, y);
  }
  for (int i = 1; i <= 199; i++) {
    adj[i].emplace_back(i + 1, x);
    adj[i + 1].emplace_back(i, x);
  }
  int start = 2 * a - 1;
  int end = 2 * b;

  priority_queue<pii, vector<pii>, greater<pii>> pq;
  vector<int> d(2 * M + 5, 2e9);
  d[start] = 0;
  pq.emplace(0, start);
  while(!pq.empty()) {
    int v = pq.top().second;
    int dv = pq.top().first;
    pq.pop();
    for (auto i : adj[v]) {
      int to = i.first;
      int dist = i.second;
      if (d[to] > d[v] + dist) {
        d[to] = d[v] + dist;
        pq.emplace(d[to], to);
      }
    }
  }
  cout << d[end] << '\n';
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