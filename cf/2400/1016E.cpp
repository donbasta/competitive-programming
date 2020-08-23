#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;

int n;
ll sy, a, b;
ll pre[N + 5];
vector<pair<ll, ll>> ve;

void solve() {
  cout << fixed << setprecision(15);
  cin >> sy >> a >> b;
  cin >> n;
  for(int i = 0; i < n; i++) {
    ll l, r;
    cin >> l >> r;
    ve.emplace_back(l, r);
    pre[i + 1] = pre[i] + (r - l);
  }
  int q;
  cin >> q;
  while(q--) {
    ll x, y;
    cin >> x >> y;
    ld l = (ld)(x * sy - a * y) / (ld)(sy - y);
    ld r = (ld)(x * sy - b * y) / (ld)(sy - y);
    ll cl = ceil(l);
    ll fr = floor(r);
    int pa = lower_bound(ve.begin(), ve.end(), make_pair(cl, 0LL)) - ve.begin();
    if(pa > 0) pa--;
    if((ld)ve[pa].second < l) pa++;
    int pb = lower_bound(ve.begin(), ve.end(), make_pair(fr, 0LL)) - ve.begin(); 
    if(pb == n || (ld)ve[pb].first > r) pb--;
    if(pb < pa) {cout << 0. << '\n'; continue;}
    ld sum = (ld) (pre[pb + 1] - pre[pa]);
    if((ld)ve[pa].first < l) sum -= (l - (ld)ve[pa].first);
    if((ld)ve[pb].second > r) sum -= ((ld)ve[pb].second - r);
    sum = sum * (ld)(y - sy) / (ld)y;
    cout << sum << '\n';
  }
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