#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> ar(n);
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  int mn = *min_element(ar.begin(), ar.end());
  bool found = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (ar[i] == mn && !found) {
      found = 1;
    } else {
      ans += (k - ar[i]) / mn;
    }
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