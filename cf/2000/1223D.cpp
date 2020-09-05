#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  map<int, int> fi, la;
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if(fi.find(x) == fi.end()) { fi[x] = i; }
    la[x] = i;
  }
  int cur = 0, r = -1, ans = -1;
  for(auto i : fi) {
    if(i.second > r) { cur++; }
    else { ans = max(ans, cur); cur = 1; }
    r = la[i.first];
  }
  ans = max(ans, cur);
  int sz = (int)fi.size();
  cout << sz - ans << '\n';
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