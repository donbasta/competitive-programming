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
    int n;
    cin >> n;
    // set<int> se;
    vector<pair<int, int>> ve;
    vector<int> res;
    for(int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      ve.emplace_back(x, i);
    }
    // sort(ve.begin(), ve.end());
    // reverse(ve.begin(), ve.end());
    vector<int> cnt(n + 1, 0);
    vector<bool> lol(n + 1, false);
    for(int i = 0; i < n; i++) {
      bool ada = false;
      for(int j = 0; j < n; j++) {
        if(ve[j].first == i) {
          lol[j] = true;
          ada = true;
          break;
        }
      }
      if(!ada) {
        for(int j = 0; j < n; j++) {
          if(lol[j])
            continue;
          res.push_back(ve[j].second);
          ve[j].first = i;
          lol[j] = true;
          break;
        }
      }
    }

    for(int i = n; i >= 1; i--){
      
    }
    cout << (int)res.size() << '\n';
    for(auto i : res) {
      cout << i << ' ';
    }
    cout << '\n';

  }

  return 0;
}
