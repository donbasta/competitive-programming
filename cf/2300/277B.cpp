#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, m;
  cin >> n >> m;
  if(m == 3) {
    if(n == 3) {
      cout << 0 << ' ' << 0 << '\n';
      cout << 0 << ' ' << 1 << '\n';
      cout << 1 << ' ' << 0 << '\n';
    } else if(n == 4) {
      cout << 0 << ' ' << 0 << '\n';
      cout << 0 << ' ' << 3 << '\n';
      cout << 3 << ' ' << 0 << '\n';
      cout << 1 << ' ' << 1 << '\n';
    } else if(n >= 5) {
      cout << -1 << '\n';
    }
  } else {
    int lol = 1e6;
    for(int i = 0; i < m; i++) {
      cout << i << ' ' << lol + i * i << '\n';
    }
    for(int i = 0; i < n - m; i++) {
      cout << i << ' ' << -(lol + i * i) << '\n';
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