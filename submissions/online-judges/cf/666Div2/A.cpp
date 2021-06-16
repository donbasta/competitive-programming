#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e5;

ll ar[N + 5];

void solve() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  if(n == 1) {
    cout << 1 << ' ' << 1 << '\n' << -ar[1] << '\n';
    cout << 1 << ' ' << 1 << '\n' << 0 << '\n';
    cout << 1 << ' ' << 1 << '\n' << 0 << '\n';
    return;
  }
  cout << 1 << ' ' << 1 << '\n' << -ar[1] << '\n';
  cout << 2 << ' ' << n << '\n';
  for(int i = 2; i <= n; i++) {
    cout << 1LL * (n - 1) * ar[i] << ' ';
  }
  cout << '\n';
  cout << 1 << ' ' << n << '\n';
  cout << 0 << ' ';
  for(int i = 2; i <= n; i++) {
    cout << 1LL * (-n) * ar[i] << ' ';
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