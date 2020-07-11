#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const int N = 3e5 + 69;

struct node {
  ll sum;
  int left;
  node(ll _sum = 0, int _left = -1) : sum(_sum), left(_left) {}
  merge(const node& a, const node& b) {
    sum = (a.sum + b.sum) % MOD;
  }
} seg[N << 2];

void push(int v) {
  if(seg[v].left == -1)
    return;
  int start = seg[v].left;
  seg[v << 1].sum += 
  seg[v << 1].left = start;
  seg[v << 1 | 1].sum += 
  seg[v << 1 | 1].left = start + ...
  seg[v].left = -1;
}

void build(int v, int s, int e) {
  if(s == e) {
    seg[v] = ar[s];
  } else {
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
    seg[v] = (seg[v << 1] + seg[v << 1 | 1]) % MOD;
  }
}

void upd(int v, int s, int e, int l, int r, int start) {
  if(l > r || r < s || l > e)
    return;
  if(l <= s && r >= e) {
    seg[v].sum = seg
  } else {
    push(v);
    int mid = (s + e) >> 1;
    upd(v << 1, s, mid, l, r);
    upd(v << 1 | 1, mid + 1, e, l, r);
    seg[v].merge(seg[v << 1], seg[v << 1 | 1]);
  }
}

node que(int v, int s, int e, int l, int r) {
  if(l > r || r < s || l > s)
    return 
  if(l <= s && r >= e) {
    return seg[v];
  } else {
    push(v);
    int mid = (s + e) >> 1;
    node ret = node();
    ret.merge(que(v << 1, s, mid, l, r), que(v << 1 | 1, mid + 1, e, l, r));
    return ret;
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
    cin >> ar[i];
  }
  build(1, 1, n);
  while(m--) {
    int type, l, r;
    cin >> type >> l >> r;
    if(type == 1) {
      que(1, 1, n, l, r);
    } else {
      cout << get(1, 1, n, l, r) << '\n';
    }
  }
  return 0;
}
