#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 3e5;

ll res, a[N + 5];
int n, q;

void upd(int pos, int val) {
  res -= max(0LL, a[pos] - a[pos + 1]);
  res -= max(0LL, a[pos - 1] - a[pos]);
  a[pos] = val;
  res += max(0LL, a[pos] - a[pos + 1]);
  res += max(0LL, a[pos - 1] - a[pos]);
}

void solve() {
  cin >> n >> q;
  for(int i = 1; i <= n; i++) { cin >> a[i]; }
  a[0] = a[n + 1] = 0;
  res = 0;
  for(int i = 1; i <= n; i++) {
    res += max(0LL, a[i] - a[i + 1]);
  }
  cout << res << '\n';
  while(q--) {
    int l, r;
    cin >> l >> r;
    int ar = a[r], al = a[l];
    upd(l, ar), upd(r, al);
    cout << res << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}