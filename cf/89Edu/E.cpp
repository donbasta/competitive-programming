#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll MOD = 998244353;
const int N = 2e5 + 69;

int n, m;
int a[N], b[N], mn[N];
map<int, int> ri, le, kiri;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for(int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  for(int i = 1; i <= n; i++) {
    ri[a[i]] = i;
  }

  mn[n + 1] = 2e9;
  int cur = m;
  for(int i = n; i >= 1; i--) {
    mn[i] = min(mn[i + 1], a[i]);
    if(mn[i] < b[cur]){
      le[b[cur]] = i;
      while(mn[i] < b[cur] && cur >= 1)
        cur--;
    }
    // cout << i << ' ' << cur << " :(\n";
  }

  bool ok = (mn[1] == b[1]);
  le[b[1]] = 0;
  for(int i = 1; i <= m; i++) {
    if(ri.find(b[i]) == ri.end() || le.find(b[i]) == le.end()){
      ok = false;
      break;
    }
  }
  if(!ok) {
    cout << 0 << '\n';
    return 0;
  } 

  ll ans = 1;
  for(int i = 2; i <= m; i++) {
    if(ri[b[i]] < le[b[i]]) {
      cout << 0 << '\n';
      return 0;
    }
    ans = 1LL * ans * (ri[b[i]] - le[b[i]]) % MOD;
  }
  cout << ans << '\n';
  return 0;
}