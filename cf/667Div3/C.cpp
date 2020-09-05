#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  cin >> n >> x >> y;
  int dif = y - x;
  for(int i = 1; i <= dif; i++) {
    if(dif % i != 0) continue;
    int cnt = dif / i;
    if(cnt >= n) { continue; }
    int l = x % i;
    if()
  }
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