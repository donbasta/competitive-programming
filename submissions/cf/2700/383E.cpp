#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 24;

void init(string s) {

}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    init(s);
  }
  for(int mask = 0; mask < (1 << N); mask++) {
    for(int i = 0; i < N; i++) {
      if(mask & (1 << i)) {
        dp[mask][1] += a[i];
      }
    }
  }
  for(int i = 0; i < N; i++) {
    for(int mask = 0; mask < (1 << N); mask++) {
      if(mask & (1 << i)) {
        dp[mask][3] += dp[mask ^ (1 << i)][2];
        dp[mask][2] += dp[mask ^ (1 << i)][1];
      }
    }
  }
  for(int i = )
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