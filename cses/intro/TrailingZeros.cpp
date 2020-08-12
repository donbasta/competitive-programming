#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int vp2(int x) {
  return (x - __builtin_popcount(x));
}

int vp5(int x) {
  int sum = 0, temp = x;
  while(temp > 0) {
    sum += temp % 5;
    temp /= 5;
  }
  return (x - sum) / 4;
}

void solve() {
  int n;
  cin >> n;
  int v2 = vp2(n);
  int v5 = vp5(n);
  cout << min(v2, v5) << '\n';
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