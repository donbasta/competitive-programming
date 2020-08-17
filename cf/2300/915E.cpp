#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int tot, n;
set<pair<int, int>> se;

void upd(int l, int r, int k) {
  if(k == 1) {

  }
  
}


void solve() {
  cin >> n >> q;
  tot = n;
  while(q--) {
    int l, r, k;
    cin >> l >> r >> k;
    upd(l, r, k);
    cout << tot << '\n';
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