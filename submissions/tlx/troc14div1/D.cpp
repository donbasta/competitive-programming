#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;

map<ll, ll> cnt;
ll ans = 1e18;
ll temp;
ll pre[N + 5], suf[N + 5];
vector<pair<ll, ll>> lul, lol;

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> ve;
  
  for(int i = 1; i <= n; i++) {
    ll x;
    cin >> x;
    cnt[x]++;
    ve.emplace_back(x);
  }
  ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
  int sz = (int)ve.size();

  ll cur = 0;
  for(int i = 0; i < sz - 1; i++) {
    ll now = ve[i + 1] - ve[i];
    lul.emplace_back(now, cnt[ve[i]] + cur);
    cur = cnt[ve[i]] + cur;
  }
  temp = 0;
  for(int i = 1; i <= sz - 1; i++) { 
    pre[i] = lul[i - 1].first * min(lul[i - 1].second, k) + pre[i - 1];
  }

  reverse(ve.begin(), ve.end());
  cur = 0;
  for(int i = 0; i < sz - 1; i++) {
    ll now = ve[i] - ve[i + 1];
    lol.emplace_back(now, cnt[ve[i]] + cur);
    cur = cnt[ve[i]] + cur;
  }
  temp = 0;
  for(int i = 1; i <= sz - 1; i++) {
    suf[i] = lol[i - 1].first * min(lol[i - 1].second, k) + suf[i - 1];
  }

  for(int i = 1; i <= sz; i++) {
    ans = min(ans, pre[i - 1] + suf[sz - i]);
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