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

  int tc;
  cin >> tc;
  while(tc--) {
    ll a, b, n;
    cin >> a >> b >> n;
    if(a < b)
      swap(a, b);
    int cnt = 0;
    while(a <= n) {
      ll temp = a;
      a = a + b;
      b = temp;
      cnt++;
    }
    cout << cnt << '\n';
  }
  return 0;
}
