#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<ll> ar(n);
  for(int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  sort(ar.begin(), ar.end());
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      if(ar[j] == ar[i]) continue;
      for(int k = j + 1; k < n; k++) {
        if(ar[k] == ar[j]) continue;
        if(ar[i] + ar[j] > ar[k]) ans++;
      }
    }
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