#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 5e4;

int ar[N + 5];

void solve() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  bool ok = true;
  for(int i = 2; i <= n; i++) {
    ok &= (ar[i] < ar[i - 1]);
  }
  cout << (ok ? "NO" : "YES");
  cout << '\n';
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