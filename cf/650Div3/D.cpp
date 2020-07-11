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
    vector<int> cnt(26);
    string s;
    int m;
    cin >> s >> m;
    vector<int> ve(m);
    for(int i = 0; i < m; i++) {
      cin >> ve[i];
    }
    for(int i = 0; i < (int)s.length(); i++) {
      cnt[s[i] - 'a']++;
    }
    vector<pair<int, int>> temp(m);
    for(int i = 0; i < m; i++) {
      temp[i] = make_pair(i, ve[i]);
    }
    string ans(m, ' ');
    int last = 25;
    while((int)temp.size() > 0) {
      vector<int> pos;
      vector<pair<int, int>> cpy;
      for(int i = 0; i < (int)(temp.size()); i++) {
        if(temp[i].second == 0)
          pos.push_back(temp[i].first);
      }
      for(int i = last; i >= 0; i--) {
        if(cnt[i] >= (int)pos.size()) {
          for(auto j : pos) {
            ans[j] = (char) (i + 97);
          }
          cnt[i] -= (int)pos.size();
          last = i - 1;
          break;
        }
      }
      for(int i = 0; i < (int)(temp.size()); i++) {
        if(temp[i].second == 0)
          continue;
        for(auto j : pos) {
          temp[i].second -= abs(j - temp[i].first);
        }
        cpy.emplace_back(temp[i].first, temp[i].second);
      }
      temp = cpy;
    }
    cout << ans << '\n';
  }
  return 0;
}
