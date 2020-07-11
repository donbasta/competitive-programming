#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tc;
  cin >> tc;
  while(tc--){
    int n;
    cin >> n;
    vector<int> ve(n + 1);
    for(int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      if(i & 1)
        x = -abs(x);
      else
        x = abs(x);
      ve[i] = x;
    }
    for(int i = 1; i <= n; i++) {
      cout << ve[i] << ' ';
    }
    cout << '\n';
  }

  return 0;
}
