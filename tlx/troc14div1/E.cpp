#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;

int n, d;
int t[N + 5], r[N + 5], c[N + 5];

inline void solve() {
  cin >> n >> d;
  t[0] = 1;
  for(int i = 1; i <= n; i++) {
    cin >> t[i] >> r[i] >> c[i];
  }
  ll sisa = 1 + d - t[n];
  for(int i = n; i >= 1; i--) {
    if(r[i] + c[i] >= sisa) { sisa = max(0LL, sisa - c[i]); }
    sisa += (t[i] - t[i - 1]);
  }
  cout << sisa << '\n';
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