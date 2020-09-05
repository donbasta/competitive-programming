#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  multiset<int> se;
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if(x == 0) continue;
    // for(int j = 1; j <= x; j++) {
    //   se.emplace(1, i);
    // }
    se.emplace(x);
  }
  int sz = (int)se.size();
  if(sz == 1) {
    cout << "T\n"; 
    return;
  }
  if(sz == 2) {
    if(*se.begin() == *(++se.begin())) {
      cout << "HL\n";
    } else {
      cout << "T\n";
    }
    return;
  }
  while((int)se.size() > 3) {
    auto sm = *se.begin();
    auto bg = *(--se.end());
    se.erase(se.find(sm));
    se.erase(se.find(bg));
    if(bg > sm) se.emplace(bg - sm);
  }
  auto it = se.begin();
  int a = *it;
  int b = *(++it);
  int c = *(++it);
  if((a + b + c) & 1) {
    cout << "T\n";
    return;
  }
  if(a + b < c) {
    cout << "T\n";
    return;
  }
  cout << "HL\n";
  return;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}