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
    vector<int> ve(n + 1);
    set<int> se[n + 1];
    for(int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      ve[i] = x;
      se[x].insert(i);
    }
    vector<int> res;
    for(int i = 1; i <= n - 2; i++) {
      // cerr << i << ' ';
      // cerr << "lol2";
      if(ve[i] == i - 1)
        continue;
      // cerr << "lol2";
      vector<int> emp;
      for(int j = i - 1; j <= n; j++) {
        if(se[j].empty())
          emp.push_back(j);
      }
      // cerr << "anjing";
      int lul = 0;
      for(auto it = se[i - 1].begin(); it != se[i - 1].end(); ++it) {
        res.push_back(*it);
        ve[*it] = emp[lul];
        se[ve[*it]].insert(*it);
        lul++;
      }
      se[i - 1].clear();
      res.push_back(i);
      se[ve[i]].erase(i);
      ve[i] = i - 1;
      for(int j = 1; j <= n; j++) {
        cout << ve[j] << ' ';
      }
      cout << '\n';
      // cerr << "lol2";
    }
    cout << (int)res.size() << '\n';
    for(auto& el : res) {
      cout << el << ' ';
    }
    cout << '\n';
  }

  return 0;
}
