#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 2e5 + 69;

int n, m, k;
int ar[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n >> m >> k;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  sort(ar + 1, ar + n + 1);
  int mx1 = ar[n];
  int mx2 = ar[n - 1];
  int sisa = m % (k + 1);
  int cnt = m / (k + 1);
  ll lol = 1LL * mx1 * k + 1LL * mx2;
  ll ans = lol * cnt + 1LL * mx1 * sisa;
  cout << ans << '\n';

  return 0;
}
