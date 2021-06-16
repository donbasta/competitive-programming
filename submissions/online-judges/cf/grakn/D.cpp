#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MX = 1e6;

int but[MX + 5];

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n), b(n), c(m), d(m);
  for(int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for(int j = 0; j < m; j++) {
    cin >> c[j] >> d[j];
  }

  for(int i = 0; i < n; i++) {
    vector<pair<int, int>> ve;
    for(int j = 0; j < m; j++) {
      int dx = c[j] - a[i] + 1;
      int dy = d[j] - b[i] + 1;
      if(dx > 0 && dy > 0) {
        ve.emplace_back(dx, dy);
      }
    }
    sort(ve.begin(), ve.end());
    int sz = (int)ve.size();

    set<pair<int, int>> se;

    int temp = 0;
    for(int i = sz; i >= 1; i--) {
      int nx = (i == 0) ? 0 : ve[i - 1].first;
      if(se.count(make_pair(temp, but[temp]))) {
        se.erase(se.find(make_pair(temp, but[temp])));
        but[temp] = min(but[temp], nx);
      } else {
        auto it = se.lower_bound(make_pair(temp + 1, -1));
        if(it == se.begin())
          but[temp] = nx;
        else
          but[temp] = min((--it)->second, nx);
      }
      se.emplace(temp, but[temp]);
      if(i > 0)
        temp = max(temp, ve[i - 1].second);
    }
  }

  int ans = 2e9;
  cerr << but[0] << '\n';
  for(int i = 1; i <= MX; i++) {
    if(i == 5) break;
    but[i] = min(but[i], but[i - 1]);
    cerr << i << ' ' << but[i] << '\n';
    ans = min(ans, i + but[i]);
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