#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5 + 5;

int n, k, cnt;
int bit[N];
ll ans;
ll pre[N];
vector<ll> ve;
map<ll, int> mp;

void upd(int x, int val) {
  while(x <= n + 1) {
    bit[x] += val;
    x += x & -x;
  }
}

int get(int x) {
  int ret = 0;
  while(x > 0) {
    ret += bit[x];
    x -= x & -x;
  }
  return ret;
}

int get(int x , int y) {
  return get(y) - get(x - 1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    pre[i] = pre[i - 1] + x;
  }
  for(int i = 0; i <= n; i++) {
    pre[i] -= 1LL * i * k;
  }
  for(int i = 0; i <= n; i++) {
    ve.push_back(pre[i]);
  }
  sort(ve.begin(), ve.end());
  ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
  for(auto i : ve) {
    mp[i] = ++cnt;
  }
  for(int i = n; i >= 0; i--) {
    int cur = mp[pre[i]];
    ans += get(cur, cnt);
    upd(cur, 1);
  }
  cout << ans << '\n';
  return 0;
}