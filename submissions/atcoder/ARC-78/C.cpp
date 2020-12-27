#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;

ll pre[N + 69];
ll ans = 1e18;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    pre[i] = pre[i - 1] + x;
  }
  for(int i = 1; i <= n - 1; i++) {
    ans = min(ans, abs(2 * pre[i] - pre[n]));
  }
  cout << ans << '\n';
  
  return 0;
}