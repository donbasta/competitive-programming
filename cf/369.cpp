#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 3e5 + 10;

int n, m, mx = -1;
vector<pair<int, int>> seg;
vector<int> t[N << 2];

void build(int v, int s, int e) {
  if(s == e) {
    t[v] = vector<int>(1, seg[s].second);
  } else {
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
    merge(t[v << 1].begin(), t[v << 1].end(), t[v << 1 | 1].begin(), t[v << 1 | 1].end(), back_inserter(t[v]));
  }
}

int get(int v, int s, int e, int l, int r, int val) {
  if(l > e || r < s || l > r) {
    return 0;
  } else if (l <= s && r >= e) {
    int pos = lower_bound(t[v].begin(), t[v].end(), val) - t[v].begin();
    return (int)t[v].size() - pos;
  } else {
    int mid = (s + e) >> 1;
    return get(v << 1, s, mid, l, r, val) + get(v << 1 | 1, mid + 1, e, l, r, val);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    int l, r;
    cin >> l >> r;
    seg.emplace_back(l, r);
    mx = max(r, mx);
  }
  sort(seg.begin(), seg.end());
  build(1, 0, n - 1);
  while(m--) {
    int cnt;
    cin >> cnt;
    vector<int> que(cnt + 1);
    que[cnt] = mx + 1;
    for(int i = 0; i < cnt; i++) {
      cin >> que[i];
    }
    sort(que.begin(), que.end(), greater<int>());
    int ans = 0;
    for(int i = 1; i <= cnt; i++) {
      int t1, t2;
      int up = upper_bound(seg.begin(), seg.end(), make_pair(que[i] + 1, 0)) - seg.begin();
      up--;
      t1 = get(1, 0, n - 1, 0, up, que[i - 1]);
      t2 = get(1, 0, n - 1, 0, up, que[i]);
      ans += (t2 - t1);
    }
    cout << ans << '\n';
  }
  return 0;
}
