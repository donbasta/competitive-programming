#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;

int n, q;
ll ar[N + 5], lz[N << 2 + 5];

void build(int v, int s, int e) {
  if(s == e) {lz[v] = ar[s]; return;}
  int mid = (s + e) >> 1;
  build(v << 1, s, mid);
  build(v << 1 | 1, mid + 1, e);
}

void push(int v) {
  if(!lz[v]) return;
  lz[v << 1] += lz[v];
  lz[v << 1 | 1] += lz[v];
  lz[v] = 0;
}

void upd(int v, int s, int e, int l, int r, int val) {
  if(l > e || r < s) return;
  if(l == e && r == s) {
    lz[v] += val;
  }
  int mid = (s + e) >> 1;
  push(v);
  upd(v << 1, s, mid, l, min(r, mid), val);
  upd(v << 1 | 1, mid + 1, e, max(mid + 1, l), r, val);
}

int get(int v, int s, int e, int pos) {
  if(s == e) return ar[pos] + lz[v];
  int mid = (s + e) >> 1;
  push(v);
  if(pos <= mid) return get(v << 1, s, mid, pos);
  else return get(v << 1 | 1, mid + 1, e, pos);
}

void solve() {
  cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  build(1, 1, n);
  while(q--) {
    int type; cin >> type;
    if(type == 1) {
      int a, b, u;
      cin >> a >> b >> u;
      upd(1, 1, n, a, b, u);
    } else {
      int k;
      cin >> k;
      cout << get(1, 1, n, k) << '\n';
    }
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