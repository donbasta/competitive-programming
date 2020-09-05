#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) { cin >> ar[i]; }
  int cur = 0;
  pos[0] = 0;
  for(int i = 0; i < n; i++) {
    if(ar[i + 1] >= ar[i]) { pos[i + 1] = pos[i]; }
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