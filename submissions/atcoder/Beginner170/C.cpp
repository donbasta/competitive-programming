#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

bool ada[200];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int x, n;
  cin >> x >> n;
  vector<int> ve;

  if(n == 0) {
    cout << x << '\n';
    return 0;
  }

  for(int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    ada[k] = true;
  }

  int mn = 200, ans = 200;
  for(int i = x; i <= 101; i++) {
    if(!ada[i]) {
      if(i - x <= mn && i < ans) {
        ans = i;
        mn = i - x;
        break;
      }
    }
  }
  for(int i = x; i >= 0; i--) {
    if(!ada[i]) {
      if(x - i <= mn && i < ans) {
        ans = i;
        mn = x - i;
        break;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
