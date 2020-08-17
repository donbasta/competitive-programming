#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;

ll n, k, w, Ans;
ll a[2], b[2], c[2], d[2];
vector<ll> l, h, ans, mx;
map<ll, ll> mp;

void solve() {
  cin >> n >> k >> w;
  mp.clear();
  mx.assign(n + 1, 0);
  ans.assign(n + 1, 0);
  l.resize(n + 1);
  h.resize(n + 1);
  for(int i = 1; i <= k; i++) {
    cin >> l[i];
    mp[l[i]] = i;
  }
  cin >> a[0] >> b[0] >> c[0] >> d[0];
  for(int i = 1; i <= k; i++) {
    cin >> h[i];
  }
  cin >> a[1] >> b[1] >> c[1] >> d[1];
  for(int i = k + 1; i <= n; i++) {
    l[i] = ((a[0] * l[i - 2] + b[0] * l[i - 1] + c[0]) % d[0]) + 1;
    h[i] = ((a[1] * h[i - 2] + b[1] * h[i - 1] + c[1]) % d[1]) + 1;
    mp[l[i]] = i;
  }
  ans[1] = 2LL * (w + h[1]) % MOD;
  for(int i = 0; i <= w; i++) {
    if(mp.find(i + l[1]) != mp.end()) {
      mx[mp[i + l[1]]] = max(mx[mp[i + l[1]]], h[1]);
    }
  }
  for(int i = 2; i <= n; i++) {
    ans[i] = ans[i - 1];
    if(l[i] > l[i - 1] + w) {
      ans[i] = (ans[i] + 2 * (h[i] + w)) % MOD;
    } else {
      if(h[i] >= mx[i]) {
        ans[i] = (ans[i] + 2 * (h[i] - mx[i]) + 2 * (l[i] - l[i - 1])) % MOD;
      } else {
        ans[i] = (ans[i] + 2 * (l[i] - l[i - 1])) % MOD;
      }
    }
    for(int j = 0; j <= w; j++) {
      if(mp.find(j + l[i]) != mp.end()) {
        mx[mp[j + l[i]]] = max(mx[mp[j + l[i]]], h[i]);
      }
    }
  }

  Ans = 1;
  for(int i = 1; i <= n; i++) {
    Ans = Ans * ans[i] % MOD;
  }
  if(Ans < 0) Ans += MOD;
  cout << Ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  
  return 0;
}