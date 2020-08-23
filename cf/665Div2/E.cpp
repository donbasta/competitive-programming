#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int MX = 1e6;
const int INF = 1e9;
const int N = 1e5 + 5;

int n, m;
vector<pii> vl, vr, hl, hr;
vector<pii> tl[N << 2], tr[N << 2];
int cnt0, cnt1;
int V, E;

void build_left(int v, int s, int e) {
  if(s == e) {tl[v] = vector<pii>(1, mp(hl[s].se, hl[s].fi)); return;}
  int mid = (s + e) >> 1;
  build_left(v << 1, s, mid);
  build_left(v << 1 | 1, mid + 1, e);
  merge(tl[v << 1].begin(), tl[v << 1].end(), tl[v << 1 | 1].begin(), tl[v << 1 | 1].end(), back_inserter(tl[v]));
}

void build_right(int v, int s, int e) {
  if(s == e) {tr[v] = vector<pii>(1, mp(hr[s].se, hr[s].fi)); return;}
  int mid = (s + e) >> 1;
  build_right(v << 1, s, mid);
  build_right(v << 1 | 1, mid + 1, e);
  merge(tr[v << 1].begin(), tr[v << 1].end(), tr[v << 1 | 1].begin(), tr[v << 1 | 1].end(), back_inserter(tr[v]));
}

void upd_left(int v, int s, int e, int l, int r, int x) {
  if(l > r || r < s || l > e) return;
  if(l <= s && r >= e) {
    int sz = (int)tl[v].size();
    int temp = lower_bound(tl[v].begin(), tl[v].end(), mp(x + 1, 0)) - tl[v].begin();
    int temp2 = lower_bound(tl[v].begin(), tl[v].end(), mp(x, 0)) - tl[v].begin();
    cnt0 += (sz - temp2);
    cnt1 += (sz - temp);
    cnt1 += (sz - temp2);
    return;
  }
  int mid = (s + e) >> 1;
  upd_left(v << 1, s, mid, l, min(mid, r), x);
  upd_left(v << 1 | 1, mid + 1, e, max(mid + 1, l), r, x);
}

void upd_right(int v, int s, int e, int l, int r, int x) {
  if(l > r || r < s || l > e) return;
  if(l <= s && r >= e) {
    int sz = (int)tr[v].size();
    int temp = lower_bound(tr[v].begin(), tr[v].end(), mp(x, 0)) - tr[v].begin();
    int temp2 = lower_bound(tr[v].begin(), tr[v].end(), mp(x + 1, 0)) - tr[v].begin();
    cnt0 += temp2;
    cnt1 += temp;
    cnt1 += temp2;
    return;
  }
  int mid = (s + e) >> 1;
  upd_right(v << 1, s, mid, l, min(mid, r), x);
  upd_right(v << 1 | 1, mid + 1, e, max(mid + 1, l), r, x);
}

void solve() {
  cin >> n >> m;
  int nempel = 0;
  for(int i = 0; i < n; i++) {
    int y, lx, rx;
    cin >> y >> lx >> rx;
    if(lx == 0) {
      if(rx == MX) nempel++;
      hl.emplace_back(y, rx);
    } else if(rx == MX) {
      hr.emplace_back(y, lx);
    }
  }
  sort(hl.begin(), hl.end());
  sort(hr.begin(), hl.end());
  if(!hl.empty()) build_left(1, 0, hl.size());
  if(!hr.empty()) build_right(1, 0, hr.size());
  for(int i = 0; i < m; i++) {
    int x, ly, ry;
    cin >> x >> ly >> ry;
    if(ly == 0) {
      if(ry == 0) nempel++;
      vl.emplace_back(x, ry);
    } else if(ry == MX) {
      vr.emplace_back(x, ly);
    }
  }
  for(auto& seg : vl) {
    int a = lower_bound(hl.begin(), hl.end(), mp(seg.second + 1, 0)) - hl.begin(); a--;
    int b = lower_bound(hr.begin(), hr.end(), mp(seg.second + 1, 0)) - hr.begin(); b--;
    if(!hl.empty()) upd_left(1, 0, hl.size(), 0, a, seg.first);
    if(!hr.empty()) upd_right(1, 0, hr.size(), 0, b, seg.first); 
  }
  j = 0;
  for(auto& seg: vr) {
    int a = lower_bound(hl.begin(), hl.end(), mp(seg.second, 0)) - hl.begin();
    int b = lower_bound(hr.begin(), hr.end(), mp(seg.second, 0)) - hr.begin();
    if(!hl.empty()) upd_left(1, 0, hl.size(), a, hl.size(), seg.first);
    if(!hr.empty()) upd_right(1, 0, hr.size(), b, hr.size(), seg.first);
  }
  int V = 4 + n + m + cnt0;
  int E = cnt1 + hr.size() + hl.size() + (4 + n + m + nempel);
  int ans = 1 + E - V;
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