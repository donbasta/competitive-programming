#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int D = 500, S = 5000;
// pair<int, int> dp[D][S + 5];

void solve() {
  cin >> d >> s;
  for(int i = 0; i < 2 * D; i++) {
    for(int j = 0; j <= S; j++) {
      for(int k = 0; k < 10; k++) {
        dp[i][j] = k * 10^i + dp[] 
      }
    }
  }

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