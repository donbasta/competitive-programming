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

  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    ll x;
    cin >> x;
    if(x <= 14) {
      cout << "NO\n";
      continue;
    }
    ll res = x % 14;
    if(res >= 1 && res <= 6)
      cout << "YES";
    else
      cout << "NO";
    cout << '\n';
  }

  return 0;
}
