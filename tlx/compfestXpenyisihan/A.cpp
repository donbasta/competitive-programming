#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tc;
  cin >> tc;
  while(tc--) {
    cin >> n;
    vector<pair<int, int>> ve(n + 1);
    map<int, set<int>> mp;
    for(int i = 1; i <= n; i++) {
      int a, b;
      cin >> a >> b;
      mp[a].insert(i);
      mp[b].insert(i);
      if(a > b)
        swap(a, b);
      ve[i] = make_pair(a, b);
    }
    ll ans = 0;
    for(auto it = mp.begin(); it != mp.end(); ++it) {
      int cnt = -1;
      if(it != mp.begin()) {
        cnt++;
      }
      cnt += (int) (it -> second).size();
      ans += 1LL * cnt * (it -> first);
      for(auto i : (it -> second)) {
        mp[ve[i].second].erase(i);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
