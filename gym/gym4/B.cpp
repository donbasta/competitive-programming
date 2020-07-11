#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 105;

int n;
bool sg;
int dp[N][N];

int mex(vector<int> ve) {
  sort(ve.begin(), ve.end());
  ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
  int sz = (int)ve.size();
  for(int i = 0; i < sz; i++) {
    if(i != ve[i])
      return i;
  }
  return sz;
}

void init() {
  for(int i = 2; i <= 100; i++) {
    dp[i][1] = dp[1][i] = i - 2;
  }
  for(int i = 2; i <= 100; i++) {
    for(int j = 2; j <= 100; j++) {
      if(i == j)
        continue;
      vector<int> temp;
      for(int t = i - 1; t >= 1; t--){
        if(t == j)
          continue;
        temp.push_back(dp[t][j]);
      }
      for(int t = j - 1; t >= 1; t--){
        if(t == i)
          continue;
        temp.push_back(dp[i][t]);
      }
      for(int t = 1; t <= min(i, j) - 1; t++){
        temp.push_back(dp[i - t][j - t]);
      }
      dp[i][j] = mex(temp);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  init();
  cin >> n;
  for(int i = 1; i <= n; i++) {
    int l, c;
    cin >> l >> c;
    if(l == c) {
      cout << 'Y' << '\n';
      return 0;
    }
    sg ^= (dp[l][c]);
  }
  if(sg)
    cout << 'Y';
  else
    cout << 'N';
  cout << '\n';
  return 0;
}
