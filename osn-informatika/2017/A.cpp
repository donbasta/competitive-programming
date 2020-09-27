#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 3e5;

int n, sd, sm;
int p[N + 5], k[N + 5], l[N + 5];

void solve() {
  string _;
  cin >> _;

  cin >> n >> sd >> sm;

  for(int i = 1; i < n; i++) {
    cin >> p[i] >> k[i] >> l[i];
  }
  p[n] = sm;

  int cur = sd;
  ll time = 0;

  multiset<int> se;
  for(int i = 1; i <= n; i++) {
    if(cur < p[i]) {
      int need = p[i] - cur;
      while(need > 0 && !se.empty()) {
        cur++;
        auto lol = *se.begin();
        time = time + lol;
        se.erase(se.begin());
        need--;
      }
      if(need > 0) {
        cout << -1 << '\n';
        return;
      }
    }
    if(i < n) {
      if(l[i] <= k[i]) {
        cur++;
      } else {
        se.emplace(l[i] - k[i]);
      }
      time += min(k[i], l[i]);
    }
  }

  cout << time << '\n';

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