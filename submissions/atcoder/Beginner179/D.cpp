#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 998244353;
const int N = 2e5;

inline void add(ll& x, ll y) { x = (x + y) % MOD; }

ll pre[N + 5], ar[N + 5];

void solve() {
  int n, k;
  cin >> n >> k;

  vector<pair<int, int>> bat;
  for(int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    bat.emplace_back(x, y);
  }
  pre[1] = ar[1] = 1;
  for(int i = 2; i <= n; i++) {
    for(int j = 0; j < k; j++) {
      add(ar[i], pre[max(0, i - bat[j].first)] - pre[max(0, i - bat[j].second - 1)]);
    }
    pre[i] = (pre[i - 1] + ar[i]) % MOD;
  }
  ar[n] %= MOD;
  if(ar[n] < 0) ar[n] += MOD;
  cout << ar[n] << '\n';
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