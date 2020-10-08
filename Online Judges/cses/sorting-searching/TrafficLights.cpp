#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int x, n;
  cin >> x >> n;
  set<int> tl;
  multiset<int> pas;
  tl.insert(0);
  tl.insert(x);
  pas.insert(x);
  for(int i = 0; i < n; i++) {
    int p;
    cin >> p;
    auto temp = tl.upper_bound(p);
    auto r = temp;
    auto l = --temp;
    int dis = *r - *l;
    pas.erase(pas.find(dis));
    pas.insert(p - *l);
    pas.insert(*r - p);
    tl.insert(p);
    cout << *pas.rbegin() << ' ';
  }
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