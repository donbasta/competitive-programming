#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100;

int n;
int ans[N + 5], pos[N + 5], ar[N + 5][N + 5];

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    ans[i] = pos[i] = i;
    for(int j = 0; j < n; j++) {
      cin >> ar[i][j];
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == j) continue;
      vector<pair<ld, int>> temp;
      for(int k = 0; k < n; k++) {
        ld cur = ((ld) ar[k][i]) / ((ld) ar[k][j]);
        temp.emplace_back(cur, k);
      }
      sort(temp.begin(), temp.end());
      reverse(temp.begin(), temp.end());
      int mxIdx = temp[0].second;
      for(int i = 0; i < n; i++) {cerr << ans[i] << ' ';}
      cerr << mxIdx << ' ';
      if(ans[mxIdx] != i) {
        int curPos = pos[i];
        swap(ans[mxIdx], ans[curPos]);
        pos[ans[mxIdx]] = mxIdx;
        pos[ans[curPos]] = curPos;
      }
      cerr << i << ' ' << j << ": ";
      for(int i = 0; i < n; i++) {cerr << ans[i] << ' ';}
      cerr << '\n';
    }
  }
  for(int i = 0; i < n; i++) {
    cout << ans[i] + 1;
    if(i < n - 1) cout << ' ';
  }
  cout << '\n';
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