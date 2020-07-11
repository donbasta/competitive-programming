#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 2e5 + 69;

ll n;
// vector<int> adj[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  ll kurang = 0;
  for(int i = 1; i < n; i++) {
    ll u, v;
    cin >> u >> v;
    if(u > v)
      swap(u, v);
    // adj[u].push_back(v);
    // adj[v].push_back(u);
    kurang += u * (n - v + 1LL);
    // cerr << kurang << '\n';
  }

  ll ans = 0;
  for(int i = 1; i <= n; i++) {
    ans = (ans + 1LL * i * (i + 1) / 2);
  }
  // cout << ans << " " << kurang << " :D";
  ans -= kurang;
  cout << ans << '\n';





  return 0;
}
