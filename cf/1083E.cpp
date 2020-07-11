#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e6 + 69;
const ll INF = 1e18 + 69;

struct line {
  ll m, c;
  line(ll _m, ll _c) : m(_m), c(_c) {}
  ll calc(ll x) {return m * x + c;}
  ld meetX(const line& l) {return (ld) (c - l.c) / (l.m - m);}
};

int n;
vector<pair<pair<ll, ll>, ll>> ve;
ll dp[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n;
  for(int i = 1; i <= n; i++) {
    ll a, x, y;
    cin >> x >> y >> a;
    ve.emplace_back(make_pair(x, y), a);
  }
  sort(ve.begin(), ve.end());

  deque<line> de;
  ll ans = 0;
  de.emplace_front(0, 0);
  // dp[0] = max(1LL * ve[0].first.first * ve[0].first.second - ve[0].second, 0LL);
  // ans = max(ans, dp[0]);
  // de.emplace_front(-ve[0].first.first, dp[0]);
  for(int i = 0; i < n; i++) {
    ll cur = ve[i].first.second;
    while((int)de.size() >= 2 && de.back().calc(cur) <= de[de.size() - 2].calc(cur))
      de.pop_back();
    dp[i] = ve[i].first.first * ve[i].first.second - ve[i].second;
    dp[i] += de.back().calc(cur);
    ans = max(ans, dp[i]);
    line next = line(-ve[i].first.first, dp[i]);
    while((int)de.size() >= 2 && next.meetX(de[0]) >= de[0].meetX(de[1])) {
      de.pop_front();
    }
    de.push_front(next);
  }
  cout << ans << '\n';
  return 0;
}
