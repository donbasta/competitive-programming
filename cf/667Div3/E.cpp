#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> ve;
  vector<int> pre(n + 1), bat(n + 1), suf(n + 1);

  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ve.emplace_back(x);
  }
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
  }
  sort(ve.begin(), ve.end());
  for(int i = 0; i < n; i++) {
    int kanan = ve[i] + k;
    int pos = upper_bound(ve.begin(), ve.end(), kanan) - ve.begin();
    
    pre[i] = pos - i;
    bat[i] = pos;
  }
  suf[n] = 0;
  pre[n] = 0;
  for(int i = n - 1; i >= 0; i--) {
    suf[i] = max(pre[i], suf[i + 1]);
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    ans = max(ans, pre[i] + suf[bat[i]]);
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