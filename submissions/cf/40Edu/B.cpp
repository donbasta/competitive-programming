#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;
string s;

void solve() {
  cin >> n >> s;
  int mx = 0;
  for(int j = 1; 2 * j <= n; j++) {
    bool ok = true;
    for(int i = 0; i < j; i++) {
      ok &= (s[i] == s[i + j]);
    }
    if(ok) mx = j;
  }
  int ans;
  if(mx > 0)
    ans = mx + 1 + (n - 2 * mx);
  else
    ans = n;
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