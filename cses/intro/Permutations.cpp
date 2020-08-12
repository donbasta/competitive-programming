#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  if(n <= 3 && n != 1) {
    cout << "NO SOLUTION" << '\n';
    return;
  }
  for(int i = 2; i <= n; i += 2) {
    cout << i << ' ';
  }
  for(int i = 1; i <= n; i += 2) {
    cout << i << ' ';
  }
  cout << '\n';
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