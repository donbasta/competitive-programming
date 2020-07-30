#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tc;
  cin >> tc;
  while(tc--) {
    cin >> n;
    vector<int> ar(2 * n + 5);
    for(int i = 0; i < 2 * n; i++) {
      cin >> ar[i + 1];
    }
    vector<int> part;
    vector<bool> udah(2 * n + 5, 0);
    int cnt = 0, curMax = 2 * n;
    for(int i = 2 * n; i >= 1; i--) {
      cnt++;
      udah[ar[i]] = true;
      if(ar[i] == curMax) {
        part.emplace_back(cnt);
        cnt = 0;
        while(curMax > 0 && udah[curMax]) {
          curMax--;
        }
      }
    }
    sort(part.begin(), part.end());
    int sz = (int)part.size();
    vector<vector<bool>> dp(sz + 5, vector<bool>(n + 5, 0));
    //cari di part ada ga yg jumlahnya = n
    dp[0][0] = true;
    if(part[0] <= n)
      dp[0][part[0]] = true;
    for(int i = 1; i < sz; i++) {
      if(part[i] <= n)
        dp[i][part[i]] = true;
      dp[i][0] = true;
      for(int j = 1; j <= n; j++) {
        dp[i][j] = dp[i - 1][j] | dp[i][j];
        if(j >= part[i])
          dp[i][j] = dp[i - 1][j - part[i]] | dp[i][j];
      }
    }
    bool ok = false;
    for(int i = 0; i < sz; i++) {
      if(dp[i][n])
        ok = true;
    }
    cout << (ok ? "YES" : "NO");
    cout << '\n';
  }
  return 0;
}