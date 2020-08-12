#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int M = 1e6;
const int MOD = 1e9 + 7;

int n, x;

void solve() {
  cin >> n >> x;
  vector<int> c(n);
  vector<int> ans(M + 1);
  for(int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for(int i = 0; i < n; i++) {
    for(int j = 1; j <= x; j++) {
      
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