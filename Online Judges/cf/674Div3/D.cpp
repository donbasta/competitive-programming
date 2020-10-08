#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<ll> ar(n + 1), pre(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
    pre[i] = pre[i - 1] + ar[i];
  }
  int ans = 0;
  map<ll, int> mp;
  
  for(int i = 1; i <= n; i++) {
    // cerr << i << ' ' << pre[i] << '\n';
    if(mp[pre[i]] == 1) {
      ans++;
      mp.clear();
    }
    mp[pre[i - 1]] = 1;
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