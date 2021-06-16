#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int n, m;
int ar[40];
set<int> se1, se2;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  int mid = (n / 2);
  for(int i = 0; i < (1 << mid); i++) {
    int sum = 0;
    for(int j = 0; j < mid; j++) {
      if((i >> j) & 1)
        sum = (sum + ar[j]) % m;
    }
    se1.insert(sum);
  }
  for(int i = 0; i < (1 << (n - mid)); i++) {
    int sum = 0;
    for(int j = 0; j < (n - mid); j++) {
      if((i >> j) & 1)
        sum = (sum + ar[mid + j]) % m;
    }
    se2.insert(sum);
  }
  int ans = 0;
  for(auto i : se1) {
    auto it = se2.lower_bound(m - i);
    if(it == se2.begin()){
      ans = max(ans, i + *(se2.rbegin()) % m);
      continue;
    }
    ans = max(ans, i + *(--it));
  }
  cout << ans << '\n';
  return 0;
}
