#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll D[5] = {1, 0, 1, 2, 9};
ll n, k, ans;

ll C(ll a, ll b) {
  ll ret = 1;
  for(int i = 0; i < b; i++) {
    ret *= (a - i);
  }
  for(int i = 1; i <= b; i++) {
    ret /= i;
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n >> k;
  for(int i = 0; i <= k; i++) {
    ans += C(n, i) * D[i];
  }
  cout << ans << '\n';
  return 0;
}
