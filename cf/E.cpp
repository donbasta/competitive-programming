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

  int n;
  cin >> n;
  vector<ll> ar(n + 1);
  for(int i = 1; i <= n; i++) {
  	cin >> ar[i];
  }
  ll mx = 0;
  for(int i = 1; i <= n; i++) {
  	for(int j = i; j <= n; j++) {
      for(int k = j; k <= n; k++) {
        mx = max(mx, ar[i] | ar[j] | ar[k]);
      }
  	}
  }
  cout << mx << '\n';

  return 0;
}
