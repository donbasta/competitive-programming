#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, k, l;
  cin >> n >> k >> l;
  int m = n * k;
  vector<ll> ar(m);
  for (int i = 0; i < m; i++) {
    cin >> ar[i];
  }
  sort(ar.begin(), ar.end());
  ll fi = ar[0];
  ll bat = ar[0] + l;
  int pos = upper_bound(ar.begin(), ar.end(), bat) - ar.begin();
  if (pos < n) {
    cout << 0 << '\n';
    return;
  }
  set<int> se;
  for (int i = 0; i < m; i++) {
    se.insert(i);
  }
  int cur = 0;
  ll ans = 0;
  while (!se.empty()) {
    if (cur == k-1) {
      auto p = se.lower_bound(pos);
      --p;
      ans += ar[*p];
      se.erase(p);
      cur = 0;
    } else {
      cur++;
      auto last = se.end();
      --last;
      se.erase(last);
    }
  }
  cout << ans << '\n';
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