#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e4;

int a[N + 5], b[N + 5], c[2 * N + 5];

void solve() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    c[i] = a[i];
  }
  for(int i = 1; i <= n; i++) {
    cin >> b[i];
    c[i + n] = b[i];
  }
  sort(c + 1, c + 2 * n + 1, greater<int>());
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    ans += c[i];
  }
  cout << ans << '\n';
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