#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 2e5 + 69;

int n;
ll ar[N], pre[N], ans;

struct line {
  ll m, c;
  line(ll _m, ll _c) : m(_m), c(_c) {}
  ll calc(ll x) {return m * x + c;}
  ld meetX(const line& l) {return (ld) (c - l.c) / (l.m - m)}; 
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
    pre[i] = pre[i - 1] + ar[i];
  }

  deque<line> dq;
  





  return 0;
}
