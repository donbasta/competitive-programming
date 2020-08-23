#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, k, ans;
  cin >> n >> k;
  if(n < k) {
    ans = k - n;
  } else {
    if((n - k) % 2 == 0) {
      ans = 0;
    } else {
      ans = 1;
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