#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<int> ar(n + 1), cek(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  for (int i = 1; i <= n - 2; i++) {
    cek[i] = abs(ar[i] - ar[i + 1]) + abs(ar[i + 1] - ar[i + 2]) - abs(ar[i] - ar[i + 2]);
  }
  int lol = 0;
  for (int i = 1; i <= n - 2; i++) {
    lol = max(lol, cek[i]);
  }
  lol = max(lol, abs(ar[2] - ar[1]));
  lol = max(lol, abs(ar[n - 1] - ar[n]));
  ll tot = 0;
  for (int i = 1; i <= n - 1; i++) {
    tot += 1LL * abs(ar[i] - ar[i + 1]);
  }
  tot -= lol;
  cout << tot << '\n';
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