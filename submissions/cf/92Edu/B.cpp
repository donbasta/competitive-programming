#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, k, z;

void solve() {
  cin >> n >> k >> z;
  vector<int> a(n), b(n - 1);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n - 1; i++) {
    b[i] = a[i] + a[i + 1];
  }
  int pre = a[0];
  int skor = a[0];
  int mx = b[0];
  for(int i = 1; i < n; i++) {
    pre += a[i];
    skor = max(skor, pre + max(0, min(z, ((k - i) / 2))) * mx);
    if(i < n - 1)
      mx = max(mx, b[i]);
  }
  cout << skor << '\n';
  return;
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