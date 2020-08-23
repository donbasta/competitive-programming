#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<int> ar(n);
  int mx = -1;
  for(int i = 0; i < n; i++) {
    cin >> ar[i];
    mx = max(mx, ar[i]);
  }
  int ans = 0, bonus = 100 - mx;
  for(int i = 0; i < n; i++) {
    ans += (ar[i] + bonus >= 50);
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