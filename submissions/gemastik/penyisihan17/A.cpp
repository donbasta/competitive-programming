#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

inline void solve() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  ll sum = 0;
  for(int i = 0; i < n; i++) { cin >> a[i]; sum += a[i]; }
  for(int i = 0; i < n; i++) { cin >> b[i]; sum += b[i]; }
  sum = sum * n;
  cout << sum << '\n';
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