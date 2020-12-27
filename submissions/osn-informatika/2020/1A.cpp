#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;

int n, q;
int h[N + 5];
vector<pair<int, int>> que, ans;
int cur = 0, idx = 0;

pair<int, int> t[4 * N + 5];

void build(int v, int s, int e) {
  if (s == e) {
    t[v] = make_pair(h[i], s);
  }
  int mid = (s + e) >> 1;
  build(v << 1, s, mid);
  build(v << 1 | 1, mid + 1, e);
  t[v] = min(t[v << 1], t[v << 1 | 1]);
}

void getMin(int v, int s, int e, int l, int r) {
  if (s == e && l == r)
    return t[v];
  int mid = (s + e) >> 1;
  if (r < mid)
    return getMin(v << 1, s, mid, l, r);
  else if (l > mid)
    return getMin(v << 1 | 1, mid + 1, e, l, r);
  else
    return min(getMin(v << 1, s, mid, l, mid), getMin(v << 1 | 1, mid + 1, e, mid + 1, r)); 
}

void fill(int l, int r, int dec) {
  if (l > r) return;
  pair<int, int> mn = getMin(1, 1, n, l, r);
  ll bat = (r - l + 1) * (mn.first - dec);
  while(idx < q && que[idx].first <= cur + bat) {
    int pos = ((que[idx].first - cur) % (r - l + 1));
    pos = ((pos == 0) ? r : (pos + l - 1)); 
    ans.emplace_back(que[idx].second, pos);
    idx++;
  }
  cur += bat;
  fill(l, mn.second - 1, mn.first);
  fill(mn.second + 1, r, mn.first);
}

void solve() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  cin >> q;
  for(int i = 1; i <= q; i++) {
    int k;
    cin >> k;
    que.emplace_back(k, i);
  }
  sort(que.begin(), que.end());
  fill(1, n, 0);
  sort(ans.begin(), ans.end());
  for(auto& e : ans) {
    cout << e << '\n';
  }
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