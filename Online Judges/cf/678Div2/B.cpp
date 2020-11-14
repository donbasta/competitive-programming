#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a = i, b = (i + 1) % n;
    for (int j = 0; j < n; j++) {
      if (j == a || j == b) {
        cout << 1 << ' ';
      } else {
        cout << 0 << ' ';
      }
    }
    cout << '\n';
  }
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