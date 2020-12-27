#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while(T--) {
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    for(int i = 1; i <= n * m; i++) {
      int x;
      cin >> x;
      ans += x;
    }
    cout << ans << '\n';
  }
  
  return 0;
}