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
    string s;
    cin >> s;
    int sz = (int)s.length(), mn = 0;
    vector<int> pref(sz + 1, 0);
    map<int, int> mp;
    for(int i = 0; i < sz; i++) {
      pref[i + 1] = pref[i] + (s[i] == '+');
      pref[i + 1] = pref[i + 1] - (s[i] == '-');
      mn = min(mn, pref[i + 1]);
      if(mp.find(pref[i + 1]) == mp.end()) {
        mp[pref[i + 1]] = i + 1;
      }
    }
    if(mn >= 0) {
      cout << sz;
    } else {
      ll res = 0;
      for(int i = 0; i < -mn; i++) {
        res += 1LL * mp[-i-1];
      }
      res += 1LL * sz;
      cout << res;
    }
    cout << '\n';
  }
  return 0;
}
