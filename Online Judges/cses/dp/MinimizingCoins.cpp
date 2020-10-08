#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int M = 1e6;
const int INF = 1e9;

int n, x;

void solve() {
  cin >> n >> x;
  vector<int> c(n);
  vector<int> ans(M + 1, INF);
  for(int i = 0; i < n; i++) {
    cin >> c[i];
    ans[c[i]] = 1;
  }
  for(int i = 1; i <= x; i++) {
    for(int j = 0; j < n; j++) {
      int sisa = i - c[j];
      if(sisa <= 0 || ans[sisa] == INF) continue;
      ans[i] = min(ans[i], ans[sisa] + 1);
    }
  }
  cout << (ans[x] == INF ? -1 : ans[x]) << '\n';
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