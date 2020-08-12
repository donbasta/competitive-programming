#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<bool> cnt(n + 1, false);
  for(int i = 0; i < n - 1; i++) {
    int x;
    cin >> x;
    cnt[x] = true;
  } 
  for(int i = 1; i <= n; i++) {
    if(!cnt[i]) {
      cout << i << '\n';
      return;
    }
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