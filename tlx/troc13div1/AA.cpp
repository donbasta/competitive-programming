#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 2e5 + 69;

int n;
set<int> se;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n;
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    se.insert(x);
  }
  int sz = (int)se.size();
  if(sz >= n - 1) {
    cout << sz << '\n';
  } else {
    cout << n - 2 << '\n';
  }
  return 0;
}
