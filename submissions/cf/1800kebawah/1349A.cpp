#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9 + 7;
const ll MOD = 1e18;
const int A = 2e5;

int cnt[A + 5];

ll fpow(ll a, ll b) {
  ll ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return ret;
}

void solve() {
  int n;
  cin >> n;
  map<int, pair<int, int>> mp;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for (int j = 2; j * j <= x; j++) {
      if (x % j == 0) {
        // cerr << j << " " << i << " " << '\n';
        cnt[j]++;
        if (!mp.count(j)) {
          mp[j] = make_pair(INF, INF);
        }
        int pw = 0;
        while (x % j == 0) {
          x /= j;
          pw++;
        }
        if (pw < mp[j].first) {
          mp[j] = make_pair(pw, mp[j].first);
        } else if (pw < mp[j].second) {
          mp[j] = make_pair(mp[j].first, pw);
        }
      }
    }
    if (x > 1) {
      cnt[x]++;
      if (!mp.count(x)) {
        mp[x] = make_pair(1, INF);
      } else {
        mp[x] = make_pair(1, mp[x].first);
      }
    }
  }
  ll ans = 1;
  for (auto i : mp) {
    // cerr << i.first << '\n';
    if (cnt[i.first] <= n - 2)
      continue;
    else if (cnt[i.first] == n - 1) 
      ans *= fpow(i.first, i.second.first);
    else
      ans *= fpow(i.first, i.second.second);
  }
  cout << ans << '\n';
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