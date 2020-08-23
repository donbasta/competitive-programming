#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> ar(n);
  int mn = INF;
  bool ok = true;
  for(int i = 0; i < n; i++) {
    cin >> ar[i];
    mn = min(mn, ar[i]);
  }
  vector<int> b = ar;
  sort(b.begin(), b.end());
  for(int i = n - 1; i >= 0; i--) {
    if(ar[i] == b[i]) continue;
    else ok &= ((ar[i] % mn) == 0);
  }
  cout << (ok ? "YES" : "NO");
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