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
    int n;
    cin >> n;
    vector<ll> ar(n + 1);
    vector<ll> pref(n + 1, 0), pev(n + 1, 0);
    cin >> ar[0];
    pref[0] = pev[0] = ar[0];
    for(int i = 1; i < n; i++) {
      cin >> ar[i];
      pref[i] = pref[i - 1] + ar[i];
      pev[i] = pev[i - 1];
      if(i % 2 == 0) 
        pev[i] += ar[i];

    }
    ll TOT = pev[n - 1];
    // cout << TOT << '\n';
    ll mx = 0;
    set<ll> se[2];
    se[1].insert(0);
    for(int i = 0; i < n; i++) {
      ll cur = pref[i] - 2 * pev[i];
      if(i % 2 == 0) {
        if(!se[0].empty()) {
          ll low = *se[0].begin();
          mx = max(mx, cur - low);
        }
        se[0].insert(cur);
      } else {
        if(!se[1].empty()) {
          ll low = *se[1].begin();
          mx = max(mx, cur - low);
        }
        se[1].insert(cur);
      }
    }
    // cout << mx << '\n';
    ll ans = TOT + mx;
    cout << ans << '\n';
  }
  return 0;
}
