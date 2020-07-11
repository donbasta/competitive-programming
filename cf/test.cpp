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


  tuple<int, int, int> k;
  k = make_tuple(1, 2, 4);
  cout << get<2>(k) << '\n';
  for(int i = 0; i < 2; i++) {
  	cout << get<const i>(k) << ' ';
  }

  return 0;
}
