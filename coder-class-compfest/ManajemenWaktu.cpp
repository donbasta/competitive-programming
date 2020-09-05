#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll f(int x) { return 1LL * x * (x - 1) / 2; }

const int N = 2e5;

pair<int, int> ti[N + 5];
int a[N + 5], b[N + 5];
unordered_map<int, int> mp;

void solve() {
  int n;
  cin >> n;
  vector<int> ve;
  for(int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    ti[i] = make_pair(x, y);
    ve.emplace_back(x), ve.emplace_back(y);
  }
  sort(ve.begin(), ve.end());
  ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
  int cnt = 0;
  for(auto i : ve) {
    mp[i] = cnt++;
  }
  for(int i = 1; i <= n; i++) {
    a[mp[ti[i].first]]++;
    b[mp[ti[i].second]]++;
  }
  ll ans = 0;
  // for(int i = 0; i < cnt; i++) {
  //   cerr << a[i] << ' ' << b[i] << '\n';
  // }
  assert(b[0] == 0);
  int cur = 0;
  for(int i = 0; i < cnt; i++) {
    cur -= b[i];
    assert(cur >= 0);
    int add = a[i];
    ans = ans + (1LL * add * cur) + f(add);
    cur += add;
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