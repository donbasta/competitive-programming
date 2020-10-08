#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int bit[20];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    for(int j = 0; j <= 19; j++) {
      if((x >> j) & 1) {
        bit[j]++;
      }
    }
  }
  vector<int> ans(n, 0);
  for(int i = 19; i >= 0; i--) {
    for(int j = 0; j < n; j++) {
      if(bit[i]) {
        ans[j] += (1 << i);
        bit[i]--;
      }
    }
  }
  ll lar = 0;
  for(auto i : ans) {
    lar = lar + 1LL * i * i;
  }
  cout << lar << '\n';
  return 0;
}
