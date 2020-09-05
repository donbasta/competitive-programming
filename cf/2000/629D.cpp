#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ld PI = acosl(-1);

struct Segtree {
  int n;
  vector<ll> t;
  Segtree(int n) : n(n) { t.assign(4 * n + 5, 0); }
  void upd(int v, int s, int e, int pos, ll val) {
    if(s == e) { assert(s == pos); t[v] = max(t[v], val); return; }
    int mid = (s + e) >> 1;
    if(pos <= mid) { upd(v << 1, s, mid, pos, val); }
    else { upd(v << 1 | 1, mid + 1, e, pos, val); }
    t[v] = max(t[v << 1], t[v << 1 | 1]);
  }
  ll que(int v, int s, int e, int l, int r) {
    if(l > r || r < s || l > e) { return 0; }
    if(l == s && r == e) { return t[v]; }
    int mid = (s + e) >> 1;
    return max(que(v << 1, s, mid, l, min(mid, r)), que(v << 1 | 1, mid + 1, e, max(mid + 1, l), r));
  }
};

void solve() {
  cout << fixed << setprecision(12);
  int n;
  cin >> n;
  vector<pair<ll, int>> ve;
  for(int i = 1; i <= n; i++) {
    ll r, h;
    cin >> r >> h;
    ve.emplace_back(r * r * h, i);
  }
  sort(ve.begin(), ve.end());
  Segtree Tree = Segtree(n);
  vector<ll> dp(n, 0);
  int j;
  for(int i = 0; i < n; i = i + j) {
    j = 1;
    while(i + j < n && ve[i + j].first == ve[i].first) { ++j; }
    for(int k = 0; k < j; k++) {
      int cur = ve[i + k].second;
      ll lol = Tree.que(1, 1, n, 1, cur - 1);
      dp[i + k] = max(dp[i + k], lol + ve[i + k].first);
    }
    for(int k = 0; k < j; k++) {
      int cur = ve[i + k].second;
      Tree.upd(1, 1, n, cur, dp[i + k]);
    }
  }
  ll ans = Tree.que(1, 1, n, 1, n);
  ld final_ans = PI * ((ld)ans);
  cout << final_ans << '\n';
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