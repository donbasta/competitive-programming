#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;
vector<int> bita, bitb;

void upd(vector<int>& bit, int x, int val) {
  for(; x <= n; x += x & (-x)) {
    bit[x] += val;
  }
}

int get(const vector<int>& bit, int x) {
  int ret = 0;
  for(; x > 0; x -= x & (-x)) {
    ret += bit[x];
  }
  return ret;
}

int getHigher(const vector<int>& bit, int x) {
  return get(bit, n) - get(bit, x);
}

void solve() {
  cin >> n;
  vector<pair<int, int>> a(n), b(n);
  vector<int> sa(n), sb(n), ca(n), cb(n), da(n), db(n);
  bita.assign(n + 1, 0);
  bitb.assign(n + 1, 0);
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    sa[i] = x;
    a[i] = make_pair(x, i);
  }
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    sb[i] = x;
    b[i] = make_pair(x, i);
  }
  if(sa == sb) {
    cout << "YES" << '\n';
    return;
  }
  sort(sa.begin(), sa.end());
  sort(sb.begin(), sb.end());
  if(sa != sb) {
    cout << "NO" << '\n';
    return;
  }
  for(int i = 0; i < n; i++) {
    ca[i] = get(bita, a[i].first - 1);
    da[i] = getHigher(bita, a[i].first);
    upd(bita, a[i].first, 1);
  }
  for(int i = 0; i < n; i++) {
    cb[i] = get(bitb, b[i].first - 1);
    db[i] = getHigher(bitb, b[i].first);
    upd(bitb, b[i].first, 1);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  bool ok = true;
  for(int i = 0; i < n; i++) {
    ok &= (ca[a[i].second] <= cb[b[i].second]);
    ok &= (da[a[i].second] >= db[b[i].second]);
  }
  cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}