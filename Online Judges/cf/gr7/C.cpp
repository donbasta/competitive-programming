#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int r, c;
  cin >> r >> c;
  if(r == 1 && c == 1) {
    cout << 0 << '\n';
  } else if(c == 1) {
    for(int i = 1; i <= r; i++) {
      cout << i + 1 << '\n';
    }
  } else {
    for(int i = 1; i <= c; i++)
      cout << i + 1 << ' ';
    cout << '\n';
    for(int i = 2; i <= r; i++) {
      for(int j = 1; j <= c; j++)
        cout << (j + 1) * (c + i) << ' ';
      cout << '\n';
    }
  }
  return 0;
}
