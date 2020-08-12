#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
  cin >> n;
  int end = (n + 3) / 4;
  string ans = "";
  for(int i = 0; i < n - end; i++) {
    ans += '9';
  }
  for(int i = 0; i < end; i++) {
    ans += '8';
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