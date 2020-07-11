#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e5 + 10;

vector<pair<ll, int>> t[N << 2];

void build(int v, int s, int e) {
  if(s == e) {
    t[v] = vector<pair<ll, int>>(1, make_pair(h[s], s));
  } else {
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
    merge(t[v << 1].begin(), t[v << 1].end(), t[v << 1 | 1].begin(), t[v << 1 | 1].end(), back_inserter(t[v]));
  }
}

void upd(int v, int s, int e, int )

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n >> d;
  for(int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  sort(h + 1, h + n + 1);
  build(1, 1, n);
  for(int i = 1; i <= n; i++) {
    // pair<int, int> t = get(1, 1, n, 1, i - 1);
    // if(t.first == )
  }

  return 0;
}
