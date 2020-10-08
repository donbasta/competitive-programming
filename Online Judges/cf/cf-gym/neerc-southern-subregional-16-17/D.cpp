#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;
const int M = 1e5;

int n;
ll cnt;
ll r;
ll pre[N + 5], len[N + 5], tim[N + 5];

bool enough(const vector<ll>& X) {
  return (int)X.size() < M;
}

ll ceil(ll a, ll b) {
  return (a + b - 1) / b;
}

void solve() {
  cin >> n >> r;
  for(int i = 1; i <= n; i++) {
    cin >> len[i];
    pre[i] = len[i] + pre[i - 1];
  }
  vector<int> ve;
  vector<ll> mo;
  for(int i = 1; i <= n; i++) {
    cin >> tim[i];
    if(len[i] > tim[i]) {
      cout << -1 << '\n';
      return;
    }
    if(2 * len[i] > tim[i]) {
      ve.emplace_back(i);
    }
  }
  ll prev = 0;
  ll now = 0;
  ll totLen = pre[n];
  for(int i = 0; i < (int)ve.size(); i++) {
    if(prev <= pre[ve[i] - 1]) {
      now += (pre[ve[i] - 1] - prev) * 2;
      prev = pre[ve[i] - 1] + (tim[ve[i]] - len[ve[i]]);
      ll start = now + 2 * (tim[ve[i]] - len[ve[i]]);
      ll Y = ceil(2 * len[ve[i]] - tim[ve[i]], r);
      ll endPoint = min(totLen, prev + Y * r);
      now = start + Y * r;
      // cerr << pre[ve[i]] << ' ' << prev << ' ' << r << '\n';
      cnt += min(Y, ceil((pre[ve[i]] - prev) , r));
      for(int j = 0; j < Y; j++) {
        if(!enough(mo)) break;
        if((prev + 1LL * j * r) >= pre[ve[i]]) break;
        mo.emplace_back(start + 1LL * j * r);
        // cerr << start + 1LL * j * r;
      }
      prev = endPoint;
    } else if(prev >= pre[ve[i]]) {
      continue;
    } else {
      if(prev + tim[ve[i]] - len[ve[i]] >= pre[ve[i]]) continue;
      prev += tim[ve[i]] - len[ve[i]];
      ll start = now + 2 * (tim[ve[i]] - len[ve[i]]);
      ll Y = ceil(pre[ve[i]] - prev, r);
      ll endPoint = min(totLen, prev + Y * r);
      now = start + Y * r;
      cnt += min(Y, ceil((pre[ve[i]] - prev) , r));
      for(int j = 0; j < Y; j++) {
        if(!enough(mo)) break;
        if((prev + 1LL * j * r) >= pre[ve[i]]) break;
        mo.emplace_back(start + 1LL * j * r);
      }
      prev = endPoint;
    }
  }
  int cap = (int)mo.size();
  cout << cnt << '\n';
  if(cnt <= M) {
    assert(cap == cnt);
    for(auto i : mo) {
      cout << i << ' ';
    }
  }
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