#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll V, N;

ll calc(int x) {
  ll sum = 1LL * V * N * x;
  return (sum + 9) / 10;
}

void solve() {
  cin >> V >> N;
  for(int i = 1; i < 10; i++) {
    cout << calc(i);
    if(i < 9) cout << ' ';
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