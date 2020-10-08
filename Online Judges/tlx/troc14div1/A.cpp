#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<int> ar(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  if(n == 1) {
    cout << 0 << '\n';
    return;
  }
  // if(2 * n - 1 <= 101) {
    cout << 101 << '\n';
    string ans = "";
    for(int i = 1; i <= 101; i++) {
      if(i & 1) ans.push_back('G');
      else ans.push_back('L');
    }
    cout << ans;
  // } else {
    // cout << -1;
  // }
  cout << '\n';
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