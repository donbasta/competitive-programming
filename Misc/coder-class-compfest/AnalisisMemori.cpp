#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<int> t(n + 1);
  t[1] = 1;
  for(int i = 2; i <= n; i++) {
    t[i] = 1 + t[i / 2] + t[(i + 1) / 2];
  }
  cout << t[n] << '\n';
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