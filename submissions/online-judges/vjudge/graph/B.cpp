#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 3e4;

int nx[N + 5];
int n, t;

inline void solve() {
  cin >> n >> t;
  for(int i = 1; i < n; i++) {
    int x;
    cin >> x;
    nx[i] = i + x;
  }
  int cur = 1;
  while(cur <= t) {
    cur = nx[cur];
    if(cur == t) {
      cout << "YES" << '\n';
      return;
    }
    if(cur == n) {
      break;
    }
  }
  cout << "NO" << '\n';
  return;
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