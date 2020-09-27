#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e3;

ll a[N + 5];

inline void solve() {
  ll n, x;
  cin >> n >> x;

  ll sum = 0;
  int cnt = 0;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
    if(a[i] == x) { cnt++; }
  }
  if(cnt == n) {
    cout << 0;
  } else if(sum == x * n || cnt > 0) {
    cout << 1;
  } else {
    cout << 2;
  }
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