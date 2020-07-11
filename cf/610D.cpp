#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MAX = 1e9 + 69;
const int N = 1e5 + 5;

int n, sz;
vector<pair<int, pair<int, int>>> hori, veri;
ll ans;
vector<pair<int, int>> t[N << 2];

bool in(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
  return (a.first == b.first) && (a.second.first <= b.second.second) && (a.second.second >= b.second.first);
}

pair<int, pair<int, int>> merge(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
  return make_pair(a.first, make_pair(min(a.second.first, b.second.first), max(a.second.second, b.second.second)));
}

void compress(vector<pair<int, pair<int, int>>>& ve) {
  vector<pair<int, pair<int, int>>> ret;
  for(int i = 0; i < (int)ve.size(); i++) {
    ret.emplace_back(ve[i]);
    while(ret.size() >= 2 && in(ret.back(), ret[ret.size() - 2])) {
      auto temp = ret.back(), temp2 = ret[ret.size() - 2];
      ret.pop_back();
      ret.pop_back();
      ret.emplace_back(merge(temp, temp2));
    }
  }
  cerr << "lol";
  ve = ret;
}

void build(int v, int s, int e) {
  if(s == e) {
    t[v] = vector<pair<int, int>>(1, hori[s].second);
  } else {
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
    merge(t[v << 1].begin(), t[v << 1].end(), t[v << 1 | 1].begin(), t[v << 1 | 1].end(), back_inserter(t[v]));
  }
}

int get(int v, int s, int e, int l, int r, int val) {
  if(l > r || r < s || l > e)
    return 0;
  if(l <= s && r >= e) {
    int ret = 0;
    int pos = lower_bound(t[v].begin(), t[v].end(), make_pair(val + 1, 0)) - t[v].begin();
    for(int i = pos - 1; i >= 0; i--) {
      if(t[v][i].second >= val)
        ret++;
    }
    return ret;
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

  cin >> n;
  for(int i = 1; i <= n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2) {
      if(y1 > y2)
        swap(y1, y2);
      veri.emplace_back(x1, make_pair(y1, y2));
    } else if(y1 == y2) {
      if(x1 > x2)
        swap(x1, x2);
      hori.emplace_back(y1, make_pair(x1, x2));
    }
  }
  sort(veri.begin(), veri.end());
  sort(hori.begin(), hori.end());
  compress(veri);
  compress(hori);

  sz = (int)hori.size();
  for(auto i : hori) {
    ans += i.second.second - i.second.first + 1;
  }
  build(1, 0, sz - 1);
  for(int i = 0; i < (int)veri.size(); i++) {
    int ov, lo, hi;
    ans += veri[i].second.second - veri[i].second.first + 1;
    lo = lower_bound(hori.begin(), hori.end(), make_pair(veri[i].second.first, make_pair(-MAX, 0))) - hori.begin();
    hi = upper_bound(hori.begin(), hori.end(), make_pair(veri[i].second.second + 1, make_pair(-MAX, 0))) - hori.begin();
    ans -= get(1, 0, sz - 1, lo, hi - 1, veri[i].first);
  }
  cout << ans << '\n';
  return 0;
}
