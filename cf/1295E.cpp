#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll INF = 1e18;
const int N = 2e5 + 5;

int n;
ll lz[N << 2], t[N << 2];
int p[N], pos[N], a[N];

void push(int v) {
  if(!lz[v]) return;
  lz[v << 1] += lz[v];
  lz[v << 1 | 1] += lz[v];
  t[v << 1] += lz[v];
  t[v << 1 | 1] += lz[v];
  lz[v] = 0;
}

void upd(int v, int s, int e, int l, int r, int val) {
  if(l > r)
    return;
  if(l == s && r == e){
    lz[v] += val;
    t[v] += val;
    return;
  }
  push(v);
  int mid = (s + e) >> 1;
  upd(v << 1, s, mid, l, min(r, mid), val);
  upd(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, val);
  t[v] = min(t[v << 1], t[v << 1 | 1]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> p[i];
    pos[p[i]] = i;
  }
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    if(i < n)
      upd(1, 1, n - 1, i, n - 1, a[i]);
  }
  ll ans = t[1];
  for(int i = 1; i <= n; i++) {
    upd(1, 1, n - 1, 1, pos[i] - 1, a[pos[i]]);
    upd(1, 1, n - 1, pos[i], n - 1, -a[pos[i]]);
    ans = min(ans, t[1]);
  }
  cout << ans << '\n';
  return 0;
}