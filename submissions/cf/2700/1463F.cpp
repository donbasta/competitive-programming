#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  cin >> n >> x >> y;
  int p = x + y;
  cnt[0] = n / p;
  int sisa = (n % p);
  for (int i = 1; i < p; i++) {
    if (i <= sisa) {
      cnt[i] = cnt[0] + 1;
    } else {
      cnt[i] = cnt[0];
    }
  }
  if (x < y) swap(x, y);
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < (1 << i); j++) {
      for (int k = 0; k < i; k++) {
        dp[i][j] += ((j & (1 << k)) ? cnt[k] : 0);
      }
    }
  }
  for (int i = y; i < p; i++) {
    for (int j = 0; j < (1 << y); j++) {
      
    }
    dp[i][]
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