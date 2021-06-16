#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;
const int N = 2e5;

ll pre[N + 5];

void solve() {
  int n;
  cin >> n;
  ll mn = 0;
  ll ans = -INF;
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    pre[i] = pre[i - 1] + x;
    ans = max(ans, pre[i] - mn);
    mn = min(mn, pre[i]);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}