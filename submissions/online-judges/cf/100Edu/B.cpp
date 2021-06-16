#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n, 1), c(n, 1);
  ll S = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    S += a[i];
  }
  for (int i = 0; i < n; i += 2) {
    b[i] = a[i];
  }
  for (int i = 1; i < n; i += 2) {
    c[i] = a[i];
  }
  ll B = 0, C = 0;
  for (int i = 0; i < n; i++) {
    B += abs(a[i] - b[i]);
    C += abs(a[i] - c[i]);
  }
  if (2 * B <= S) {
    for (int i = 0; i < n; i++) {
      cout << b[i] << ' ';
    }
    cout << '\n';
    return;
  } else if (2 * C <= S) {
    for (int i = 0; i < n; i++) {
      cout << c[i] << ' ';
    }
    cout << '\n';
    return;
  }
  assert(false);
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