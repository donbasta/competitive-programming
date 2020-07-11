#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  vector<int> ve;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ve.emplace_back(x);
  }
  sort(ve.begin(), ve.end(), greater<int>());
  int cur = 1;
  int tot = 1;
  ll sum = ve[0];
  while(tot < n - 1) {
    sum = sum + 1LL * ve[cur];
    tot++;
    if(tot == n - 1) break;
    sum = sum + 1LL * ve[cur];
    tot++;
    cur++;
  }
  cout << sum << '\n';

  return 0;
}
