#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, W;
  cin >> n >> W;

  vector<int> w(n + 1), v(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> w[i] >> v[i];
  }

  vector<ll> val(W + 1, -1);
  for(int i = 1; i <= n; i++) {
    // for(int j = 1; j <= 15; j++) {
    //   cerr << j << ' ' << val[j] << '\n';
    // }
    for(int j = 0; j <= W; j++) {
      if(j >= w[i])
        if(val[j - w[i]] != -1)
          val[j] = max(val[j], val[j - w[i]] + v[i]);
    }
    // for(int j = 1; j <= 15; j++) {
    //   cerr << j << ' ' << val[j] << '\n';
    // }
    val[w[i]] = max(val[w[i]], 1LL * v[i]);
    // for(int j = 1; j <= 15; j++) {
    //   cerr << j << ' ' << val[j] << '\n';
    // }
    // cerr << "--------";
  }
  for(int i = 1; i <= W; i++) {
    cerr << i << ' ' << val[i] << '\n';
  }
  ll ans = *max_element(val.begin(), val.end());
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