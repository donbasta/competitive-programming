#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  string S, T, ans;
  cin >> S >> T;
  ans = T;
  if(S == "Y") {
    if(T == "a") ans = "A";
    else if(T == "b") ans = "B";
    else if(T == "c") ans = "C";
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