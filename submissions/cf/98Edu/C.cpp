#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  string s;
  cin >> s;
  int a = 0, b = 0, ans = 0;
  for (auto& c : s) {
    if (c == '(') a++;
    if (c == ')') {
      if (a > 0) {
        ans++, a--;
      }
    }
    if (c == '[') b++;
    if (c == ']') {
      if (b > 0) {
        ans++, b--;
      }
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