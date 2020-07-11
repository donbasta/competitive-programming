#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e5 + 69;
const ll INF = 1e18 + 69;

ll a[N], b[N], dp[N];
int n;

struct line {
  ll m, c;
  line(ll _m, ll _c) : m(_m), c(_c) {}
  ll calc(ll x) {return m * x + c;}
  ld meetX(const line& l) {return (ld) (c - l.c) / (l.m - m);}
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  ll ans = INF;
  deque<line> dq;
  dp[1] = 0LL;
  dq.emplace_back(b[1], dp[1]);
  for(int i = 2; i <= n; i++) {
    ll cur = a[i];
    while((int)dq.size() >= 2 && dq[0].calc(cur) >= dq[1].calc(cur)) {
      dq.pop_front();
    }
    dp[i] = dq.front().calc(cur);
    line next = line(b[i], dp[i]);
    while((int)dq.size() >= 2 && next.meetX(dq.back()) <= dq.back().meetX(dq[dq.size() - 2])) {
      dq.pop_back();
    }
    dq.push_back(next);
  }
  cout << dp[n] << '\n';
  return 0;
}
