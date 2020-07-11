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

  int tc;
  cin >> tc;
  while(tc--) {
    int n;
    cin >> n;
    vector<int> a(n), ar(2);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      if(abs(a[i] - i) % 2 != 0) {
        ar[i & 1]++;
      }
    }
    if(ar[0] != ar[1]) {
      cout << -1;
    } else {
      cout << ar[0];
    }
    cout << '\n';
  }

  return 0;
}
