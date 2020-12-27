#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;

ll ar[N + 5];

void solve() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  sort(ar + 1, ar + n + 1);
  ll curCost = 0;
  for(int i = 2; i <= n; i++) {
    curCost += ar[i] - ar[1];
  }
  ll ans = curCost;
  for(int i = 2; i <= n; i++) {
    curCost += 1LL * (i - 1) * (ar[i] - ar[i - 1]);
    curCost += 1LL * (n - i + 1) * (ar[i - 1] - ar[i]);
    ans = min(ans, curCost);
  }
  cout << ans << '\n';
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