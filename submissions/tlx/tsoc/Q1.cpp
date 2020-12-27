#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, k, lol, afk;
  cin >> n >> k;
  string pos;
  set<int> se;
  for(int i = 1; i <= n; i++) {
    se.insert(i);
  }
  if(n & 1) {
    cout << "First" << endl;
    while((int)se.size() > 1) {
      cout << *se.begin() << endl;
      se.erase(se.begin());
      cin >> lol;
      lol = abs(lol);
      if(!se.count(lol)) {
        cin >> afk;
        assert(afk == 0);
        return;
      }
      se.erase(se.find(lol));
    }
    cout << *se.begin() << endl;
  } else {
    cout << "Second" << endl;
    while((int)se.size() > 0) {
      cin >> lol;
      lol = abs(lol);
      if(!se.count(lol)) {
        cin >> afk;
        assert(afk == 0);
        return;
      }
      se.erase(se.find(lol));
      cout << *se.begin() << endl;
      se.erase(se.begin());
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  // cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}