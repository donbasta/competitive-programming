#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<int> ar(n + 1);
  for(int i = 1; i <= n; i++) { cin >> ar[i]; }
  ll ans = 0;
  vector<int> l(n + 1);
  for(int i = 1; i <= n; i++) {
    vector<int> r(n + 1);
    for(int j = n; j >= i + 1; j--) {
      ans += 1LL * l[ar[j]] * r[ar[i]];
      r[ar[j]]++;
    }
    l[ar[i]]++;
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