#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5 + 5;
const int MAX = 30;

int ar[N];
int t[N << 2];

void build(int v, int s, int e) {
  if(s == e) {
    t[v] = ar[s];
    return;
  }
  int mid = (s + e) >> 1;
  build(v << 1, s, mid);
  build(v << 1 | 1, mid + 1, e);
  t[v] = t[v << 1] & t[v << 1 | 1];
}

int que(int v, int s, int e, int l, int r) {
  if(l > r || l > e || r < s) {
    return (1 << MAX) - 1;
  }
  if(l <= s && r >= e) {
    return t[v];
  }
  int mid = (s + e) >> 1;
  int a = que(v << 1, s, mid, l, min(mid, r));
  int b = que(v << 1 | 1, mid + 1, e, max(mid + 1, l), r);
  return a & b;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tc;
  cin >> tc;
  while(tc--) {
    int n, q;
    cin >> n;
    for(int i = 1; i <= n; i++) {
      cin >> ar[i];
    }
    build(1, 1, n);
    cin >> q;
    while(q--) {
      int l, r;
      cin >> l >> r;
      cout << que(1, 1, n, l, r) << '\n';
    }
  }
  
  return 0;
}