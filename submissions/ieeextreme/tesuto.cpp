#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = double;

const ld PI = acos(-1);
const ld eps = 1e-10;
const int INF = 1e9;

void solve() {
  int n;
  cin >> n;

  vector<pair<ld, int>> pos;
  vector<int> preNeg(n + 5, 0);
  int cnt[2];
  cnt[0] = cnt[1] = 0;

  for(int i = 0; i < n; i++) {
    ld x1, x2;
    int y;
    cin >> x1 >> x2 >> y;
    if(x1 == 0 && x2 == 0) continue;
    cnt[max(0, y)]++;
    ld theta = acos (abs(x1) / sqrt(x1*x1 + x2*x2));
    // ld theta = acos (abs(x1) / hypot(abs(x1), abs(x2)));
    if (x1 < 0) theta = PI - theta;
    if (x2 < 0) theta = PI * 2 - theta;
    pos.emplace_back(theta, y);
  }

  n = (int)pos.size();

  if(n <= 1) {
    cout << "YES" << '\n';
    return;
  }

  sort(pos.begin(), pos.end());

  // cerr << cnt[0] << ' ' << cnt[1] << '\n';

  if(cnt[0] == n || cnt[1] == n) {
    for(int i = 0; i < n; i++) {
      int ni = (i + 1) % n;
      ld dif = pos[ni].first - pos[i].first;
      if(dif < 0) dif += PI * 2;
      if(dif >= PI - eps) {
        cout << "YES" << '\n';
        return;
      }
    }
    cout << "NO" << '\n';
    return; 
  }

  for(int i = 1; i <= n; i++) {
    preNeg[i] = preNeg[i - 1] + (pos[i - 1].second == -1);
  }

  // for(auto i : pos) {
  //   cerr << i.first << ' ' << i.second << '\n';
  // }

  for(int i = 0; i < n; i++) {
    ld now = pos[i].first;
    ld bat = now + PI;

    if(bat >= PI * 2) {
      bat -= PI * 2;
      swap(bat, now);
    }

    assert(now < bat);

    int nx1 = lower_bound(pos.begin(), pos.end(), make_pair(bat - eps, -INF)) - pos.begin();
    nx1--;
    int nx2 = upper_bound(pos.begin(), pos.end(), make_pair(bat + eps, INF)) - pos.begin();
    int lw2 = upper_bound(pos.begin(), pos.end(), make_pair(now + eps, INF)) - pos.begin();
    int lw1 = lower_bound(pos.begin(), pos.end(), make_pair(now - eps, -INF)) - pos.begin();
    lw1--;
    
    int negKiri = preNeg[nx1 + 1] - preNeg[lw2];
    int negKanan = preNeg[n] + preNeg[lw1 + 1] - preNeg[nx2];
    int sumKiri = nx1 + 1 - lw2;
    int sumKanan = n + lw1 + 1 - nx2;

    // cerr<<now<<' '<<nx1+1<<' '<<nx2+1<<' '<<lw1+1<<' '<<lw2+1<<'\n';
    // cerr<<i<<' '<<negKiri<<' '<<negKanan<<' '<<sumKiri<<' '<<sumKanan<<'\n';

    if (negKiri == sumKiri && negKanan == 0) {
      cout << "YES" << '\n';
      return;
    } 
    if (negKiri == 0 && negKanan == sumKanan) {
      cout << "YES" << '\n';
      return;
    }
  }

  // cerr << "tes";

  int l = 0, r = n - 1;
  int ujung = pos[l].second;

  while(l < n && pos[l].second == ujung) 
    l++;
  while(r >= 0 && pos[r].second == ujung)
    r--;
  int idx = l;
  while (idx <= r) {
    if (pos[idx].second == ujung) {
      cout << "NO" << '\n';
      return;
    }
    idx++;
  }
  if (pos[r].first - pos[l].first <= PI + eps){
    int nr = (r + 1) % n;
    ld dif = pos[l - 1].first - pos[nr].first;
    if (dif < 0) dif += PI * 2;
    if (dif <= PI + eps)
      cout << "YES" << '\n';
    else 
      cout << "NO" << '\n';
  } else{
    cout << "NO" << '\n';
  }
  return;
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