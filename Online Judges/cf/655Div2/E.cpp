#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main() {

  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> ve(n + 1);
  for(int i = 0; i < n; i++) {
    cin >> k[i];
    for(int j = 0; j < k[i]; j++) {
      int l, r;
      cin >> l >> r;
      ve[i].emplace_back(l, r);
    }
  }

  vector<bool> ada(n + 1, true);
  vector<bool> udh(m + 1, false);
  int cnt = n;
  vector<vector<bool>> isi(n + 1);
  for(int i = 0; i < n; i++) {
    isi[i].assign(m, false);
  }
  while(cnt) {
    // vector<int> ptr(n + 1, 0);
    for(int i = 0; i < m; i++) {
      if(udah[i])
        continue;
      for(int j = 0; j < n; j++) {
        if(!isi[j][iv[j][i]]) {
          isi[j][iv[j][i]] = true;
          lol[j]++;
          byk[i]++;
        }
      }
      ans += byk[i] * byk[i];
      udh[i] = true;
    }
    for(int i = 0; i < n; i++) {
      if(lol[i] == k[i]) {
        cnt--;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}