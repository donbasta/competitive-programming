#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tc;
  cin >> tc;
  while(tc--) {
    int n, m;
    cin >> n >> m;
    vector<int> h(n + 1), t(n + 1), v(m + 1);
    vector<ll> sum(m + 1), ans(m + 1);

    for(int i = 1; i <= n; i++) {
      cin >> h[i];
    }
    for(int i = 1; i <= n; i++) {
      cin >> t[i];
    }
    for(int i = 1; i <= m; i++) {
      cin >> v[i];
    }
    for(int i = 1; i <= n; i++) {
      sum[t[i]] += 1LL * h[i];
    }
    for(int i = 1; i <= m; i++) {
      ans[i] = (sum[i] + v[i] - 1) / (1LL * v[i]);
    }
    ll mx = -1, idx = -1;
    for(int i = 1; i <= m; i++) {
      if(ans[i] > mx) {
        mx = ans[i];
        idx = i;
      }
    }
    cout << idx << '\n';
  }

  return 0;
}
