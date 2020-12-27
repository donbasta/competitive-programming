#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  int sum = 0;
  int mx = -1;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    mx = max(a, mx);
    sum += a;
  }
  if ((n == 1) || (sum & 1)) {
    cout << "Dora" << '\n';
    return;
  }
  if (2*mx > sum) {
    cout << "Dora";
  } else {
    cout << "Boots";
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