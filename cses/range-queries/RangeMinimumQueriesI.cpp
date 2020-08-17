#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9 + 7;
const int N = 2e5 + 10;

int t[N << 2];
int ar[N];
int n, q;

void build(int v, int s, int e) {
  if(s == e) {t[v] = ar[s]; return;}
  int mid = (s + e) >> 1;
  build(v << 1, s, mid);
  build(v << 1 | 1, mid + 1, e);
  t[v] = min(t[v << 1], t[v << 1 | 1]);
}

int que(int v, int s, int e, int l, int r) {
  if(l > e || r < s) return INF;
  if(l == s && r == e) return t[v];
  int mid = (s + e) >> 1;
  return min(que(v << 1, s, mid, l, min(r, mid)), que(v << 1 | 1, mid + 1, e, max(mid + 1, l), r));
}

void solve() {
  cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  build(1, 1, n);
  while(q--) {
    int a, b;
    cin >> a >> b;
    cout << que(1, 1, n, a, b) << '\n';
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