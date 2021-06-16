#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<int> ar(n), cnt(1005);
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  for (int i = 2; i <= 1000; i++) {
    for (int j = 0; j < n; j++) {
      cnt[i] += (ar[j] % i == 0);
    }
  }
  int ans = 2, mx = cnt[2];
  for (int i = 2; i <= 1000; i++) {
    if (mx < cnt[i]) {
      mx = cnt[i];
      ans = i;
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