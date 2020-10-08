#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, k;
vector<int> ar;

bool ok(int x) {
  int cur = ar[0];
  int cnt = 1;
  for(int i = 1; i < n; i++) {
    if(ar[i] - cur < x) { continue; }
    cur = ar[i];
    cnt++;
  }
  return (cnt >= k);
}

inline void solve() {
  cin >> n >> k;
  ar.resize(n);
  for(int i = 0; i < n; i++) { cin >> ar[i]; }
  sort(ar.begin(), ar.end());
  int l = 0, r = ar[n - 1] - ar[0];
  int ans = -1;  
  while(l <= r) {
    int mid = (l + r) >> 1;
    if(ok(mid)) { ans = mid, l = mid + 1; }
    else { r = mid - 1; }
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