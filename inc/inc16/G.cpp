#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e5 + 5;
const ll MOD = 1e9 + 7;

int solve() {
  int n;
  cin >> n;
  vector<int> pos[N];
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    pos[x].emplace_back(i);
  }
  int ans = 0;
  for(int i = 1; i <= N - 5; i++) {
    if(pos[i].empty() || (int) pos[i].size() == 1)
      continue;
    int sz = (int) pos[i].size();
    int cur = -(sz - 1);
    for(int j = 0; j < sz; j++) {
      ans = (1LL * ans + 1LL * cur * pos[i][j]) % MOD;
      cur += 2;
    }
    ans = (1LL * ans - 1LL * sz * (sz - 1) / 2) % MOD;
  }
  if(ans < 0)
    ans += MOD;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  for(int tc = 1; tc <= T; tc++) {
    cout << "Case #" << tc << ": ";
    cout << solve() << '\n';
  }
  
  return 0;
}