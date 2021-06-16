#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll n, m, k;
vector<vector<ll>> ar;

ll f(int a, int b) {
  ll ret = 0;
  for (int i = 0; i < m; i++) {
    ret += max(ar[a][i], ar[b][i]);
  }
  return ret;
}

ll ternary_search(int l, int r, int idx){
  while(r - l >= 3){
    int m1 = l + (r - l)/3;
    int m2 = r - (r - l)/3;
    ll f1 = f(m1, idx);
    ll f2 = f(m2, idx);
    if(f1 < f2){
      l = m1 + 1;
    } else {
      r = m2;
    }
  }
  ll maks = f(l, idx);
  for(; l <= r; l++){
    maks = max(maks, f(l, idx));
  }
  return maks;
}

int inter(pair<int, int> a, pair<int, int> b) {
  int le = max(a.first, b.first);
  int ri = min(a.second, b.second);
  if (ri < le) return 0;
  return ri - le + 1;
}

void solve() {
  cin >> n >> m >> k;

  vector<pair<int, int>> ve;
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    ve.emplace_back(l, r);
  }

  ar.assign(n - k + 1, vector<ll>(m));
  for (int i = 0; i < n - k + 1; i++) {
    for (int j = 0; j < m; j++) {
      ar[i][j] = inter(make_pair(i, i + k - 1), ve[j]);
    }
  }

  ll ans = -1e18;
  for (int i = 0; i < n - k + 1; i++) {
    ll mx = ternary_search(0, n - k, i);
    ans = max(ans, mx);
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