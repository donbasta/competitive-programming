#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  cin >> n >> m >> d;
  vector<int> a(n), b(m);
  for(int i = 0; i < n; i++) {
    
  }
  for(int i = 0; i < m; i++) {
    int x; cin >> x; b.insert(x);
    bs += x;
  }
  if(d >= as + bs) {
    cout << 1 << '\n'; return;
  } 
  if(d < bs) {
    cout << 0 << '\n'; return;
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