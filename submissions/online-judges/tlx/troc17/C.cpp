#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2000;
const int MOD = 998244353;
int ar[N + 5];

void solve() {
  int n;
  cin >> n;
  if (n > 2000) {
    cout << 0 << '\n';
    return;
  }
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  int ans = 1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ans = (1LL * ans * (ar[i] ^ ar[j])) % MOD;
    }
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