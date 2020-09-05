#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int m = 2e5 + 3;

int fastexpo(int a, int b, int m) {
  int ret = 1;
  while(b) {
    if(b & 1) { ret = 1LL * ret * a % m; }
    a = 1LL * a * a % m;
    b >>= 1;
  }
  ret %= m;
  if(ret < 0) ret += m;
  return ret;
}

int solve(int a, int b, int m) {
    a %= m, b %= m;
    int n = sqrt(m) + 1;

    int an = 1;
    for (int i = 0; i < n; ++i)
        an = (an * 1ll * a) % m;

    unordered_map<int, int> vals;
    for (int q = 0, cur = b; q <= n; ++q) {
        vals[cur] = q;
        cur = (cur * 1ll * a) % m;
    }

    for (int p = 1, cur = 1; p <= n; ++p) {
        cur = (cur * 1ll * an) % m;
        if (vals.count(cur)) {
            int ans = n * p - vals[cur];
            return ans;
        }
    }
    return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  for(int i = 2; i < m; i++) {
    int inv = fastexpo(i, m - 2, m);
    int lol = solve(i, inv, m);
    // cerr << lol << '\n';
    if(i % 10000 == 0) { cerr << i << '\n'; }
    if(lol == m - 2) {
      cout << i << ' ';
      break;
    }
  }

  
  return 0;
}