#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ve[x % m].emplace_back(x, i);
  }
  int start = -1;
  for(int i = 0; i < m; i++) {
    int temp = (int) ve[i].size();
    if()
    if(temp < (n / m) && start == -1) continue;
    if(temp > ())
  }
  for(int i = 0; i < start; i++) {

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