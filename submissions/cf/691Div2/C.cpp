#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, m;

void solve() {
  cin >> n >> m;
  vector<ll> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  if (n == 1) {
    for (int i = 0; i < m; i++) {
      cout << a[0] + b[i] << ' '; 
    }
    cout << '\n';
    return;
  }
  ll fpb = 0;
  for (int i = 1; i < n; i++) {
    fpb = __gcd(fpb, abs(a[0] - a[i]));
  }
  for (int i = 0; i < m; i++) {
    ll ret = __gcd(fpb, b[i] + a[0]);
    cout << ret << ' ';
  }
  cout << '\n';
  return;
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