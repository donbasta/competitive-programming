#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  int er = 0, ans;
  for(int i = 0; i < n; i++) {
    er += (s[i] == 'R');
  }
  ans = min(er, n - er);
  if(n & 1) {
    cout << ans << '\n';
    return;
  }
  int temp = 0;
  for(int i = 0; i < n; i += 2) {
    temp += (s[i] == s[i + 1]);
  }
  ans = min(ans, temp);
  temp = 0;
  for(int i = 1; i < n; i += 2) {
    int next = (i + 1) % n;
    temp += (s[i] == s[next]);
  }
  ans = min(ans, temp);
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