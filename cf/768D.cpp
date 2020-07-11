#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

vector<vector<ld>> dp;
ld now = 0;
int k, q;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> k >> q;
  vector<ld> lol(k + 1, 0);
  lol[0] = 1.0;
  dp.push_back(lol);
  for(int i = 1; 2 * now < 1; i++) {
    vector<ld> temp(k + 1);
    temp[0] = 0.0;
    for(int t = 1; t <= k; t++) {
      temp[t] = ((ld) t / (ld) k) * dp[i - 1][t] + ((ld) (k - t + 1) / (ld) k) * dp[i - 1][t - 1];
    }
    now = temp[k];
    dp.push_back(temp);
  }
  int sz = (dp).size();
  while(q--) {
    int p, ans = -1;
    cin >> p;
    ld bound = ((ld) p / (ld) (2000)) - 5e-11;
    for(int i = 0; i < sz; i++) {
      if(dp[i][k] >= bound) {
        ans = i;
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
