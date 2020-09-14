#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

inline void solve() {
  string s;
  cin >> s;
  int n = (int) s.length();
  int mx = 0, cur = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] != 'a') { cur = 0; }
    else { cur++; }
    mx = max(mx, cur);
  }
  for(int i = 0; i < mx + 1; i++) {
    cout << 'a';
  }
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