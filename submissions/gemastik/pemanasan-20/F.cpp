#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
int prv, cur;

inline void solve() {
  int n;
  cin >> n;
  cin >> prv;
  int ans = INF;
  for(int i = 1; i < n; i++) { 
    cin >> cur;
    ans = min(ans, cur - prv + 1);
    prv = cur; 
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