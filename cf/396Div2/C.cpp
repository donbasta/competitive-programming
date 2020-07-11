#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e3 + 69;
const int MOD = 1e9 + 7;

int n, ar[30], dp[N], pre[N][30], mn[N];
string s;

bool valid(int a, int b) {
  bool ok = true;
  for(int i = 0; i < 26; i++) {
    if(b - a > ar[i] && pre[b][i] > pre[a][i]) {
      ok = false;
      break;
    }
  }
  return ok;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n >> s;
  for(int i = 0; i < 26; i++) {
    cin >> ar[i];
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 26; j++) {
      pre[i + 1][j] = pre[i][j];
    }
    pre[i + 1][s[i] - 'a']++;
  }
  int mx = 0;
  mn[0] = 0;
  dp[0] = 1;
  for(int i = 1; i <= n; i++) {
    mn[i] = 1 + mn[i - 1];
    for(int j = i - 1; j >= 0; j--) {
      if(valid(j, i)){
        mx = max(mx, i - j);
        dp[i] = (dp[i] + dp[j]) % MOD;;
        mn[i] = min(mn[i], 1 + mn[j]);
      } else break;
    }
  }

  cout << dp[n] << '\n';
  cout << mx << '\n';
  cout << mn[n] << '\n';
  return 0;
}