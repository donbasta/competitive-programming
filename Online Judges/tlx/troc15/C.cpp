#pragma gcc optimize ("O2")
#pragma gcc optimize ("O3")
#pragma gcc optimize ("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define pii pair<int, int>
#define mp make_pair

const int N = 2e5 + 5;

int n;
int ar[N];
vector<pii> t[4 * N];
vector<int> pos[N];

vector<pii> merge(const vector<pii>& a, const vector<pii>& b, int s, int mid, int e) {
  vector<pii> ret;
  for (auto& c : a) {
    int x = upper_bound(pos[c.second].begin(), pos[c.second].end(), e) - pos[c.second].begin();
    int y = lower_bound(pos[c.second].begin(), pos[c.second].end(), mid+1) - pos[c.second].begin();
    if (x == y) {
      ret.push_back(c);
    }
  }
  for (auto& c : b) {
    int x = upper_bound(pos[c.second].begin(), pos[c.second].end(), mid) - pos[c.second].begin();
    int y = lower_bound(pos[c.second].begin(), pos[c.second].end(), s) - pos[c.second].begin();
    if (x == y) {
      ret.push_back(c);
    }
  }
  return ret;
}

void build(int v, int s, int e) {
  if (s == e) {
    t[v] = {mp(s, ar[s])};
    return;
  }
  int mid = (s + e) >> 1;
  build(v<<1, s, mid), build(v<<1 | 1, mid+1, e);
  t[v] = merge(t[v<<1], t[v<<1 | 1], s, mid, e);
}

vector<pii> get(int v, int s, int e, int l, int r) {
  if (s == l && e == r) {
    return t[v];
  }
  int mid = (s+e) >> 1;
  if (r <= mid)
    return get(v<<1, s, mid, l, r);
  else if (l > mid)
    return get(v<<1 | 1, mid+1, e, l, r);
  else
    return merge(get(v<<1, s, mid, l, mid), get(v<<1 | 1, mid+1, e, mid+1, r), l, mid, r);
}

bool ask(int l, int r) {
  if (l >= r) return 1;
  vector<pii> que = get(1, 1, n, l, r);
  if (que.empty()) {
    return 0;
  }
  assert(!que.empty() == 1);
  int tl = l;
  bool ret = 1;
  for (auto& elem : que) {
    ret &= (ask(tl, elem.first-1));
    tl = elem.first+1;
  }
  ret &= ask(tl, r);
  return ret;
  // return (ask(l, m-1) && ask(m+1, r));
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> ar[i];
    pos[ar[i]].push_back(i);
  }
  build(1, 1, n);
  bool ans = ask(1, n);
  cout << (ans ? "YES" : "NO");
  cout << '\n';
  return;
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