#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, q;
  string s;
  cin >> n >> q >> s;
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    int idx = l, last = -1, prv = -1;
    bool flag = 0;
    bool flag1 = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == s[idx]) {
        if (idx > l) {
          if (i > prv + 1) {
            flag1 = 1;
          }
        }
        prv = i;
        idx++;
        if (idx == r) {
          flag = 1;
          last = i;
          break;
        }
      }
    }
    if (!flag) {
      cout << "NO" << '\n';
      continue;
    }
    int pos = -1;
    for (int i = n - 1; i > last; i--) {
      if (s[i] == s[r]) {
        pos = i;
        break;
      }
    }
    // cerr << pos << ' ' << flag1 << '\n';
    if (pos == -1 || (!flag1 && pos == last + 1)) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
    }
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