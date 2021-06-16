#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

inline ll calc(int x) {
  return 1LL * x * (x - 1) / 2;
}

inline int hi(int x) {
  int ret = -1;
  while(x > 0) {
    x /= 2;
    ret++;
  }
  return ret;
}

void solve() {
  int n;
  cin >> n;

  vector<int> cnt(35);
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    cnt[hi(x)]++;
  }
  ll ans = 0;
  for(int i = 0; i < 35; i++) {
    ans += calc(cnt[i]);
  }
  cout << ans << '\n';
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