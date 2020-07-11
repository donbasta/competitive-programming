#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 2e5 + 69;

int n, m, ta, tb, k;
int a[N], b[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n >> m >> ta >> tb >> k;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for(int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  if(k >= min(n, m)) {
    cout << -1 << '\n';
    return 0;
  }
  int ans = b[k + 1] + tb;
  int late = a[k + 1] + ta;
  int pos = lower_bound(b + 1, b + m + 1, late) - (b + 1);
  if(pos == m) {
    cout << -1 << '\n';
    return 0;
  } else {
    ans = max(ans, b[pos + 1] + tb);
  }
  cout << ans << '\n';
  return 0;
}
