#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;
const ll INF = 1e9;

vector<pair<ll, ll>> pre;
ll npre[2 * N + 5];
ll w[N + 5];

void solve() {
  int n;
  cin >> n;
  ll sum = 0;

  pre.emplace_back(0, 0);
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
    sum += w[i];
    ll a = pre[i - 1].first + w[i];
    pre.emplace_back(a, i);
    npre[i] = npre[i - 1] + pre[i].first;
  }
  for (int i = n + 1; i <= 2*n; i++) {
    ll a = pre[i - 1].first + w[i-n];
    pre.emplace_back(a, i);
    npre[i] = npre[i - 1] + pre[i].first;
  }

  ll ans = 0;
  int r = 0;
  for (int i = 1; i <= n; i++) {
    int bat = upper_bound(pre.begin(), pre.end(), make_pair(pre[i-1].first + (sum / 2), INF)) - pre.begin();
    bat--;
    int to = pre[bat].second;
    if (2LL*(pre[bat].first - pre[i-1].first) == sum) r++;
    ans += npre[to] - npre[i-1] - pre[i - 1].first * (to-i+1);
  }
  if (r > 0)
    ans -= (sum/2) * (r/2);

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