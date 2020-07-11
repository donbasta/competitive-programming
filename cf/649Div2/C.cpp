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
    int n, x;
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
      cin >> ar[i];
    }
    if(x == 1) {
      cout << -1 << '\n';
      continue;
    }
    
  }

  return 0;
}
