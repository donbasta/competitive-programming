#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<int> ar(n);
  int ans = 0;
  for(int i = 0; i < n; i++) {
    cin >> ar[i];
    if (ar[i] == 0) ans++;
  }
  int l = 0;
  while (l < n && ar[l] == 0) {
    ans--; l++;
  }
  int r = n - 1;
  while (r >= 0 && ar[r] == 0) {
    ans--; r--;
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