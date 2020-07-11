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

  int n;
  cin >> n;

  int ar[n + 5];
  int mx = 0;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
    mx = max(ar[i], mx);
  }

  int ans = 0;
  int cnt = 0;
  for(int i = 1; i <= n; i++) {
    if(ar[i] == mx)
      cnt++;
    else {
      ans = max(ans, cnt);
      cnt = 0;
    }
  }
  ans = max(ans, cnt);
  cout << ans << '\n';
  return 0;
}
