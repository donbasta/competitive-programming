#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int r, c;
  int sum = 0;

  cin >> r >> c;

  vector<vector<int>> ar(r + 1, vector<int>(c + 1));
  vector<vector<int>> pre(r + 1, vector<int>(c + 1));
  for(int i = 0; i < r; i++) {
    string s;
    cin >> s;
    for(int j = 0; j < c; j++) {
      ar[i + 1][j + 1] = (s[j] - '0');
      sum += (s[j] - '0');
    }
  }
  for(int i = 1; i <= r; i++) {
    for(int j = 1; j <= c; j++) {
      pre[i][j] = pre[i][j - 1] + pre[i - 1][j] + ar[i][j] - pre[i - 1][j - 1];
    }
  }
  int ans = 1e9;
  for(int i = 1; i * i <= sum; i++) {
    if(sum % i != 0) continue;
    int a = i, b = sum / i;
    if(a <= r && b <= c) {
      for(int ni = a; ni <= r; ni++) {
        for(int nj = b; nj <= c; nj++) {
          int kot = pre[ni][nj] - pre[ni][nj - b] - pre[ni - a][nj] + pre[ni - a][nj - b];
          ans = min(ans, sum - kot);
        }
      }
    }
    swap(a, b);
    if(a <= r && b <= c) {
      for(int ni = a; ni <= r; ni++) {
        for(int nj = b; nj <= c; nj++) {
          int kot = pre[ni][nj] - pre[ni][nj - b] - pre[ni - a][nj] + pre[ni - a][nj - b];
          ans = min(ans, sum - kot);
        }
      }
    }
  }
  if(ans == 1e9) {
    cout << -1;
  } else {
    cout << ans;
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