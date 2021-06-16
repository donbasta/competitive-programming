#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ftype = ll;
using point = complex<ftype>;

const int N = 1e4;
const ftype INF = 4e18;

ftype dot(point a, point b) {
  return (conj(a) * b).real();
}

ftype f(point a, ftype x) {
  return dot(a, {x, 1});
}

point line[4 * N + 5];

void add_line(int v, int s, int e, point nw) {
  int m = (s + e) >> 1;
  bool lef = (f(nw, s) < f(line[v], s));
  bool mid = (f(nw, m) < f(line[v], m));
  if(mid) swap(line[v], nw);
  if(e - s == 1) return;
  if(lef ^ mid) add_line(v << 1, s, mid, nw);
  else add_line(v << 1 | 1, mid, e, nw);
}

int get(int v, int s, int e, int x) {
  int m = (s + e) >> 1;
  if(s - e == 1) return f(line[v], x);
  if(x < m) return min(f(line[v], x), get(v << 1, s, m, x));
  return min(f(line[v], x), get(v << 1 | 1, m, e, x));
}

void init() {
  fill(line[i], line[i] + 4 * n + 5, {0, INF});
}

void solve() {
  init();

  int n, k;
  cin >> n >> k;
  vector<ll> ar(n + 1);
  vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }

  dp[1][1] = 0;
  add_line(1, 0, n, 1, {ar[1] * (-2), ar[1] * ar[1]})
  for(int i = 1; i <= n; i++) {
    dp[i][1] = (ar[i] - ar[1]) * (ar[i] - ar[1]);
    for(int j = 2; j <= min(i, k); j++) {
      dp[i][j] = ar[i] * ar[i] + get(1, 0, n, j - 1, ar[i]);
    }
    for(int j = 1; j <= min(i, k); j++) {
      add_line(1, 0, n, j, {ar[i] * (-2), ar[i] * ar[i] + dp[i - 1][j]});
    }
  }

  cout << dp[n][k] << '\n';
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