#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 3e5 + 69;

ll n, x, y, z, last, cycle, now, sg;
ll ar[N];
map<vector<ll>, ll> mp;
vector<ll> dp[3];

ll mex(vector<ll> ve) {
  for(ll i = 0; i <= 3; i++) {
    bool ok = true;
    for(auto j : ve)
      ok &= (j != i);
    if(ok)
      return i;
  }
  return -1;
}

tuple<ll, ll, ll> calc(ll p) {
  if(p < 0)
    return make_tuple(0LL, 0LL, 0LL);
  if(p >= last) {
    p -= now;
    p %= cycle;
    p += now;
  }
  return make_tuple(dp[0][p], dp[1][p], dp[2][p]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc;
  cin >> tc;
  while(tc--) {
    cin >> n >> x >> y >> z;
    for(int i = 1; i <= n; i++) {
      cin >> ar[i];
    }
    now = 0;
    last = -1;
    for(int i = 0; i < 3; i++) {
      dp[i].push_back(0);
    }
    while(true) {
      now++;
      ll a = mex({dp[0][max(now - x, 0LL)], dp[1][max(now - y, 0LL)], dp[2][max(0LL, now - z)]});
      ll b = mex({dp[0][max(now - x, 0LL)], dp[2][max(now - z, 0LL)]});
      ll c = mex({dp[0][max(now - x, 0LL)], dp[1][max(now - y, 0LL)]});
      dp[0].push_back(a);
      dp[1].push_back(b);
      dp[2].push_back(c);
      if(now >= 5) {
        vector<ll> last5;
        for(int i = 1; i <= 5; i++) {
          for(int j = 0; j < 3; j++) {
            last5.push_back(dp[j][now - i]);
          }
        }
        if(mp.find(last5) != mp.end()) {
          last = mp[last5];
          break;
        }
        mp[last5] = now;
      }
    }
    cycle = now - last;
    sg = 0;
    for(int i = 1; i <= n; i++) {
      sg ^= get<0>(calc(ar[i]));
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      ll cur = sg ^ get<0>(calc(ar[i]));
      if((cur ^ get<0>(calc(ar[i] - x))) == 0){
        ans++;
      }
      if((cur ^ get<1>(calc(ar[i] - y))) == 0){
        ans++;
      }
      if((cur ^ get<2>(calc(ar[i] - z))) == 0){
        ans++;
      }
    }
    cout << ans << '\n';
    for(int i = 0; i < 3; i++) dp[i].clear();
    mp.clear();
  }
  return 0;
}
