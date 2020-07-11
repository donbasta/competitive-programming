#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e5 + 5;

ll ans = 0;
int x, y, h, v;
vector<pair<int, int>> ve[2];
vector<int> t[2][4 * N];

void build(int v, int s, int e, int idx) {
  if(s == e)
    t[idx][v] = vector<int>(1, ve[idx][s].second);
  else {
    int mid = (s + e) >> 1;
    build(v << 1, s, mid, idx);
    build(v << 1 | 1, mid + 1, e, idx);
    merge(t[idx][v << 1].begin(), t[idx][v << 1].end(), t[idx][v << 1 | 1].begin(), t[idx][v << 1 | 1].end(), back_inserter(t[idx][v]));
  }
} 

int get(int v, int s, int e, int l, int r, int val, int idx) {
  if(e < l || s > r || l > r)
    return 0;
  if(l <= s && e <= r) {
    int k = upper_bound(t[idx][v].begin(), t[idx][v].end(), val) - t[idx][v].begin();
    return (int) t[idx][v].size() - k;
  }
  int mid = (s + e) >> 1;
  int ret = get(v << 1, s, mid, l, r, val, idx);
  ret += get(v << 1 | 1, mid + 1, e, l, r, val, idx);
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> x >> y >> h >> v;
  ans = 1LL * (h + 1) * (v + 1);
  for(int i = 1; i <= h; i++) {
    int a, b;
    cin >> a >> b;
    ve[0].emplace_back(a, b);
  }
  for(int i = 1; i <= v; i++) {
    int a, b;
    cin >> a >> b;
    ve[1].emplace_back(a, b);
  }
  for(int i = 0; i < 2; i++) {
    sort(ve[i].begin(), ve[i].end());
  }
  build(1, 0, h - 1, 0);
  build(1, 0, v - 1, 1);
  for(int i = 1; i < h; i++) {
    ans += 1LL * get(1, 0, h - 1, 0, i - 1, ve[0][i].second, 0);
  }
  for(int i = 1; i < v; i++) {
    ans += 1LL * get(1, 0, v - 1, 0, i - 1, ve[1][i].second, 1);
  }
  cout << ans << '\n';
  return 0;
}
