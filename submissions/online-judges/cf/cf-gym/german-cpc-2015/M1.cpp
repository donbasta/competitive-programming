#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9 + 7;

int n, k;

void isi(vector<int>& mn, const vector<int>& a) {
  assert (a[0] == (int)mn.size());
  assert (n == (int)a.size());
  mn[0] = 0;
  set<pair<int, int>> se;
  for(int i = 0; i < a[0]; i++) {
    se.emplace(mn[i], i);
  }
  while(!se.empty()) {
    auto now = *se.begin();
    se.erase(se.begin());
    int x = now.first, y = now.second;
    for(int i = 1; i < n; i++) {
      int nx = x + a[i];
      int ny = (y + a[i]) % a[0];
      if(mn[ny] > nx) {
        se.erase(se.find(make_pair(mn[ny], ny)));
        mn[ny] = nx;
        se.emplace(mn[ny], ny);
      }
    }
  }
}

void solve() {
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> mn(a[0], INF);
  isi(mn, a);
  cin >> k;
  while(k--) {
    int b;
    cin >> b;
    bool ok = (b >= mn[b % a[0]]);
    cout << (ok ? "TAK" : "NIE") << '\n';
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