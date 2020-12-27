#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int B = 18;
const int N = 1e5;

int seg[B][4 * N + 5];
bool lz[B][4 * N + 5], stat[B][4 * N + 5];
int ar[N + 5];

void build(int v, int s, int e, int id) {
  if(s == e) {
    seg[id][v] = (ar[s] >> id) & 1;
    return;
  }
  int mid = (s + e) >> 1;
  build(v << 1, s, mid, id), build(v << 1 | 1, mid + 1, e, id);
  seg[id][v] = seg[id][v << 1] + seg[id][v << 1 | 1];
}

void push(int v, int s, int e, int id) {
  if(!lz[id][v]) return;
  int mid = (s + e) >> 1;
  seg[id][v << 1] = (mid - s + 1) - seg[id][v << 1];
  seg[id][v << 1 | 1] = (e - mid) - seg[id][v << 1 | 1];
  lz[id][v << 1] ^= 1;
  lz[id][v << 1 | 1] ^= 1;
  lz[id][v] ^= 1;
  stat[id][v] = 0;
}

void upd(int v, int s, int e, int l, int r, int id) {
  if(l > r || l  > e || r < s) return;
  if(l <= s && r >= e) {
    seg[id][v] = (e - s + 1) - seg[id][v];
    lz[id][v] ^= 1;
    return;
  }
  push(v, s, e, id);
  int mid = (s + e) >> 1;
  upd(v << 1, s, mid, l, min(mid, r), id), upd(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, id);
  seg[id][v] = seg[id][v << 1] + seg[id][v << 1 | 1];
}

int que(int v, int s, int e, int l, int r, int id) {
  if(l > r || l  > e || r < s) return 0;
  if(l <= s && r >= e) {
    return seg[id][v];
  }
  push(v, s, e, id);
  int mid = (s + e) >> 1;
  return que(v << 1, s, mid, l, min(mid, r), id) + que(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, id);
}

void solve() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  for(int i = 0; i < B; i++) {
    build(1, 1, n, i);
  }
  int m;
  cin >> m;
  while(m--) {
    int tp; cin >> tp;
    int l, r;
    cin >> l >> r;
    if(tp == 1) {
      ll ret = 0;
      for(int i = 0; i < B; i++) {
        ret = ret + (1LL << i) * que(1, 1, n, l, r, i);
      }
      cout << ret << '\n';
    } else if(tp == 2) {
      int x;
      cin >> x;
      for(int i = 0; i < B; i++) {
        if(!((x >> i) & 1)) continue;
        upd(1, 1, n, l, r, i);
      }
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