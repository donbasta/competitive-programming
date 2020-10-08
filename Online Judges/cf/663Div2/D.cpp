#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9 + 7;

vector<int> getbit(int x) {
  return {(x >> 2) & 1, (x >> 1) & 1, (x >> 0) & 1};
}

vector<int> possible(int x) {
  if(x == 0) {return {2, 5};}
  if(x == 1) {return {3, 4};}
  if(x == 2) {return {0, 7};}
  if(x == 3) {return {1, 6};}
  if(x == 4) {return {1, 6};}
  if(x == 5) {return {0, 7};}
  if(x == 6) {return {3, 4};}
  if(x == 7) {return {2, 5};}
  return vector<int>();
}

void solve() {
  int n, m;
  cin >> n >> m;
  if(n >= 4 && m >= 4) {
    cout << -1 << '\n';
    return;
  }
  if(n == 1 || m == 1) {
    cout << 0 << '\n';
    return;
  }
  char C[n][m];
  char ar[n][m];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> C[i][j];
      ar[i][j] = C[i][j] - '0';
    }
  }
  if(n == 2) {
    vector<int> lol(m);
    for(int i = 0; i < m; i++) {
      lol[i] = ar[0][i] + ar[1][i];
    }
    int ans = INF;
    for(int i = 0; i < 2; i++) {
      int temp = 0;
      for(int j = 0; j < m; j++) {
        if(((lol[j] & 1) ^ (j & 1)) ^ i) temp++;
      }
      ans = min(ans, temp);
    }
    cout << ans << '\n';
    return;
  }
  if(m == 2) {
    vector<int> lol(n);
    for(int i = 0; i < n; i++) {
      lol[i] = ar[i][0] + ar[i][1];
    }
    int ans = INF;
    for(int i = 0; i < 2; i++) {
      int temp = 0;
      for(int j = 0; j < n; j++) {
        if(((lol[j] & 1) ^ (j & 1)) ^ i) temp++;
      }
      ans = min(ans, temp);
    }
    cout << ans << '\n';
    return;
  }
  if(n == 3) {
    int dp[m][8];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < 8; i++) {
      vector<int> wow = getbit(i);
      dp[0][i] = (ar[0][0] != wow[0]) + (ar[1][0] != wow[1]) + (ar[2][0] != wow[2]);
    }
    for(int i = 1; i < m; i++) {
      for(int j = 0; j < 8; j++) {
        vector<int> wow = getbit(j);
        dp[i][j] = (ar[0][i] != wow[0]) + (ar[1][i] != wow[1]) + (ar[2][i] != wow[2]);
        vector<int> wowo = possible(j);
        int mn = INF;
        for(auto t : wowo) {
          mn = min(mn, dp[i - 1][t]);
        }
        dp[i][j] += mn;
      }
    }
    int ans = INF;
    for(int i = 0; i < 8; i++) {
      ans = min(ans, dp[m - 1][i]);
    }
    cout << ans << '\n';
    return;
  }
  if(m == 3) {
    int dp[n][8];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < 8; i++) {
      vector<int> wow = getbit(i);
      dp[0][i] = (ar[0][0] != wow[0]) + (ar[0][1] != wow[1]) + (ar[0][2] != wow[2]);
    }
    for(int i = 1; i < n; i++) {
      for(int j = 0; j < 8; j++) {
        vector<int> wow = getbit(j);
        dp[i][j] = (ar[i][0] != wow[0]) + (ar[i][1] != wow[1]) + (ar[i][2] != wow[2]);
        vector<int> wowo = possible(j);
        int mn = INF;
        for(auto t : wowo) {
          mn = min(mn, dp[i - 1][t]);
        }
        dp[i][j] += mn;
      }
    }
    int ans = INF;
    for(int i = 0; i < 8; i++) {
      ans = min(ans, dp[n - 1][i]);
    }
    cout << ans << '\n';
    return;
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