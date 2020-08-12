#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void answer(int a, int b, int c, int d) {
  cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
}

void solve() {
  cin >> n;
  if(n <= 30) {
    cout << "NO" << '\n';
    return;
  }
  cout << "YES" << '\n';
  if(n == 36) {
    answer(6, 10, 15, 5);
  } else if(n == 40) {
    answer(6, 10, 15, 9);
  } else if(n == 44) {
    answer(6, 10, 15, 13);
  } else {
    answer(6, 10, 14, n - 30);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}