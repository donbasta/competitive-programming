#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<ll> ar(n+1), pre(n+1), mxp(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> ar[i];
    pre[i] = pre[i-1] + ar[i];
    mxp[i] = max(mxp[i-1], pre[i]);
  }
  ll mx = 0;
  for (int i = 1; i <= n; i++) {
    mx = max(mx, pre[i-1] + mxp[i]);
    pre[i] += pre[i-1];
  }
  cout << mx << '\n';
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