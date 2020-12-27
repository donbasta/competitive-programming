#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;

  vector<int> pre(n + 1), ar(n + 1), ve;
  vector<bool> l(n + 1);

  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  } 
  for(int i = 1; i <= n; i++) {
    int x; cin >> x;
    l[i] = x;
    if(!l[i]) { ve.push_back(ar[i]); }
  }
  sort(ve.begin(), ve.end(), greater<int>());
  int idx = 0;
  for(int i = 1; i <= n; i++) {
    if(!l[i]) { ar[i] = ve[idx++]; }
  }
  for(int i = 1; i <= n; i++) {
    cout << ar[i] << ' ';
  }
  cout << '\n';
  // for(int i = 1; i <= n; i++) {
  //   pre[i] = pre[i - 1] + ar[i];
  // }
  // for(int i = n; i >= 1; i--) {
  //   if(pre[i] < 0) {
  //     cout << i << '\n';
  //     return;
  //   }
  // }
  // cout << 0 << '\n';
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