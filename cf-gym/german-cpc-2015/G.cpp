#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1200;

int n;
int a[N + 5];

void solve() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  bool ok = true;
  for(int i = 1; i <= n; i++) {
    for(int j = i + 1; j <= n; j++) {
      ok &= ((a[j] - a[i]) >= 0);
    }
  }
  cout << (ok ? "yes" : "no") << '\n';
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