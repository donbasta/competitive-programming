#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> ve(n);
  for(int i = 0; i < n; i++) {
    cin >> ve[i];
  }
  sort(ve.begin(), ve.end());
  int l = 0, r = n - 1, ans = 0;
  while(l < r) {
    if(ve[l] + ve[r] <= x) {
      l++; r--;
    } else {
      r--;
    }
    ans++;
  }
  if(l == r) {
    ans++;
  }
  cout << ans << '\n';
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