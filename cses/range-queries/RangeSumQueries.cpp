#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9 + 7;
const int N = 2e5 + 10;

ll t[N << 2];
ll ar[N];
int n, q;

void build(int v, int s, int e) {
  if(s == e) {t[v] = ar[s]; return;}
  int mid = (s + e) >> 1;
  build(v << 1, s, mid);
  build(v << 1 | 1, mid + 1, e);
  t[v] = t[v << 1] + t[v << 1 | 1];
}

void upd(int v, int s, int e, int pos, int val) {
  if(s == e) {t[v] = val; return;}
  int mid = (s + e) >> 1;
  if(pos <= mid) upd(v << 1, s, mid, pos, val);
  else upd(v << 1 | 1, mid + 1, e, pos, val);
  t[v] = t[v << 1] + t[v << 1 | 1];
}

ll que(int v, int s, int e, int l, int r) {
  if(l > e || r < s) return 0;
  if(l == s && r == e) return t[v];
  int mid = (s + e) >> 1;
  return que(v << 1, s, mid, l, min(r, mid)) + que(v << 1 | 1, mid + 1, e, max(mid + 1, l), r);
}

void solve() {
  cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  build(1, 1, n);
  while(q--) {
    int type, a, b;
    cin >> type >> a >> b;
    if(type == 1) {
      upd(1, 1, n, a, b);
    } else {
      cout << que(1, 1, n, a, b) << '\n';
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