#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  int r[2], s[2], p[2];
  for(int i = 0; i < 2; i++) { 
    cin >> r[i] >> s[i] >> p[i]; 
  }
  int mx = min(r[0], s[1]) + min(s[0], p[1]) + min(p[0], r[1]);
  int mn = 0;
  if(r[1] >= r[0] + s[0]) {
    mn = (r[1] - (r[0] + s[0]));
  } else if(s[1] >= s[0] + p[0]) {
    mn = (s[1] - (s[0] + p[0]));
  } else if(p[1] >= p[0] + r[0]) {
    mn = (p[1] - (p[0] + r[0]));
  } 
  cout << mn << ' ' << mx << '\n';
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