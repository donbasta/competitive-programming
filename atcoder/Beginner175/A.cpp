#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  string S;
  cin >> S;
  int ans = 0;
  if(S == "RRR") {ans = 3;}
  else if((S == "RRS") || (S == "SRR")) {ans = 2;}
  else if(S == "SSS") {ans = 0;}
  else ans = 1;
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