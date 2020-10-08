#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;

set<pair<ll, ll>> se;

ll n, k, Ans;
vector<ll> l, h, w, ans;
ll a[3], b[3], c[3], d[3];

void solve() {
  se.clear();
  cin >> n >> k;
  l.resize(n + 1);
  h.resize(n + 1);
  w.resize(n + 1);
  ans.resize(n + 1);
  for(int i = 1; i <= k; i++) {
    cin >> l[i];
  }
  cin >> a[0] >> b[0] >> c[0] >> d[0];
  for(int i = 1; i <= k; i++) {
    cin >> w[i];
  }
  cin >> a[1] >> b[1] >> c[1] >> d[1];
  for(int i = 1; i <= k; i++) {
    cin >> h[i];
  }
  cin >> a[2] >> b[2] >> c[2] >> d[2];
  for(int i = k + 1; i <= n; i++) {
    l[i] = (((a[0] * l[i - 2] % d[0]) + (b[0] * l[i - 1] % d[0]) + c[0]) % d[0]) + 1;
    w[i] = (((a[1] * w[i - 2] % d[1]) + (b[1] * w[i - 1] % d[1]) + c[1]) % d[1]) + 1;
    h[i] = (((a[2] * h[i - 2] % d[2]) + (b[2] * h[i - 1] % d[2]) + c[2]) % d[2]) + 1;
  }

  ans[1] = 2LL * (w[1] + h[1]) % MOD;
  se.emplace(l[1], l[1] + w[1]);
  for(int i = 2; i <= n; i++) {
    ll curLeft = l[i];
    ll curRight = l[i] + w[i];
    ll newRight, newLeft;
    ans[i] = ans[i - 1];
    auto itr = se.upper_bound(make_pair(curRight, 0));
    if(itr == se.begin()) {
      se.emplace(curLeft, curRight);
      ans[i] = (1LL * ans[i - 1] + 2LL * (w[i] + h[i])) % MOD;
      continue;
    }
    --itr;
    ll cekRight = itr->second;
    newRight = max(cekRight, curRight);
    if(cekRight < curLeft) {
      se.emplace(curLeft, curRight);
      ans[i] = (1LL * ans[i - 1] + 2LL * (w[i] + h[i])) % MOD;
      continue;
    }
    if(cekRight < curRight) {
      ans[i] = (1LL * ans[i] + 2LL * (curRight - cekRight)) % MOD; 
    }
    ll cekLeft = itr->first;
    auto tempIt = itr;
    for(auto it = itr;; --it) {
      if(it->second < curLeft) break;
      cekLeft = it->first;
      tempIt = it;
      if(it == se.begin()) break;
    }
    if(cekLeft > curLeft) {
      ans[i] = (1LL * ans[i] + 2LL * (cekLeft - curLeft)) % MOD; 
    }
    newLeft = min(curLeft, cekLeft);
    vector<pair<ll, ll>> ve;
    for(auto it = itr;; --it) {
      if(it != tempIt) {
        auto temp = it; --temp;
        ans[i] = (1LL * ans[i] + 2LL * (it->first - temp->second)) % MOD;
        ans[i] = (1LL * ans[i] - 2LL * h[i]) % MOD;
      }
      ve.emplace_back(it->first, it->second);
      if(it == tempIt) break;
    }
    for(auto i : ve) {
      se.erase(se.find(i));
    }
    se.emplace(newLeft, newRight);
  }
  Ans = 1;
  for(int i = 1; i <= n; i++) {
    // cerr << ans[i] << '\n';
    Ans = (1LL * Ans * ans[i]) % MOD;
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