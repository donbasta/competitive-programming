#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 998244353;

ll fastexpo(ll a, ll b) {
  ll res = 1;
  while(b) {
    if(b & 1) { res = (res * a) % MOD; }
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

ll inv(ll a) {
  return fastexpo(a, MOD - 2);
}

const int N = 1e6;

int n;
vector<int> gift[N + 1];
int adj[N + 1];

void solve() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    while(t--) {
      int x;
      cin >> x;
      gift[i].push_back(x);
      adj[x]++;
    }
  }

  ll ans = 0;
  for(int i = 1; i <= n; i++) {
    ll sum = 0;
    int pp = (int) gift[i].size();
    if(pp != 0) {
      for(auto j : gift[i]) {
        sum = (sum + adj[j]) % MOD;
      }
      ans = (ans + inv(pp) * sum) % MOD;
    }
  }
  ans = (ans * inv(n)) % MOD;
  ans = (ans * inv(n)) % MOD;
  if(ans < 0) ans += MOD;
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