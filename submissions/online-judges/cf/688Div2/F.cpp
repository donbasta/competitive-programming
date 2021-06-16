#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<int> ar(n + 1);
  vector<bool> bisa(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  bisa[n] = 1;
  int ans = 0;
  for (int i = n; i >= 1; i--) {
    if (ar[i] == 0) continue;
    int cnt = 0;
    vector<int> ve;
    for (int j = i + 1; j <= i + ar[i]; j++) {
      if (bisa[j]) {
        // cerr << i << ' ' << j << " cek\n";
        cnt++;
        ve.emplace_back(j);
      }
    }
    // cerr << i << ' ' << cnt << '\n';
    if (cnt == 1) {
      bisa[i] = 1;
    } else if (cnt >= 2) {
      bisa[i] = 1;
      // cerr << (int)ve.size() << '\n';
      for (int j = 0; j <= (int)ve.size() - 2; j++) {
        bisa[ve[j]] = 0;
        ar[ve[j]] = 0;
        // cerr << i << ' ' << ve[j] << " tes\n";
        ans++;
      }
    }
  }
  cout << ans << '\n';
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