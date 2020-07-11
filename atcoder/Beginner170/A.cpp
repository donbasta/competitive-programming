#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int pos = 0;
  for(int i = 1; i <= 5; i++) {
    int x;
    cin >> x;
    if(x == 0)
      pos = i;
  }
  cout << pos << '\n';
  return 0;
}
