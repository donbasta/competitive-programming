#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, k;
  vector<ll> pos, neg;
  int zero = 0;

  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    ll x;
    cin >> x;
    if(x > 0) {
      pos.push_back(x);
    } else if(x < 0) {
      neg.push_back(-x);
    } else {
      zero++;
    }
  }

  if(zero > n - k) {
    cout << 0 << '\n';
  } else {
    sort(pos.begin(), pos.end(), greater<ll>());
    sort(neg.begin(), neg.end(), greater<ll>());
    priority_queue<ll> pq;
    if(k % 2 == 0) {
      for(int i = 0; i + 1 < (int)pos.size(); i += 2) {
        ll x = (pos[i] * pos[i + 1]);
        pq.emplace(x);
      }
      for(int i = 0; i + 1 < (int)neg.size(); i += 2) {
        ll x = (neg[i] * neg[i + 1]);
        pq.emplace(x);
      }
      ll res = 1;
      int tot = 0;
      while(!pq.empty() && tot < k) {
        ll temp = (pq.top()) % MOD;
        pq.pop();
        res = (res * temp) % MOD;
        tot += 2;
      }
      if(tot == k) {
        cout << res << '\n';
      } else {
        if(zero == 0) {
          res = (res * pos[pos.size() - 1]) % MOD;
          res = (res * neg[neg.size() - 1] * (-1LL)) % MOD;
          if(res < 0)
            res = (res + MOD) % MOD;
          cout << res << '\n';
        } else {
          cout << 0 << '\n';
        }
      }
    } else {
      if(!pos.empty()) {
        ll res = pos[0];
        int tot = 1;
        for(int i = 1; i + 1 < (int)pos.size(); i += 2) {
          ll x = (pos[i] * pos[i + 1]);
          pq.emplace(x);
        }
        for(int i = 0; i + 1 < (int)neg.size(); i += 2) {
          ll x = (neg[i] * neg[i + 1]);
          pq.emplace(x);
        }
        while(!pq.empty() && tot < k) {
          ll temp = (pq.top()) % MOD;
          pq.pop();
          res = (res * temp) % MOD;
          tot += 2;
        }
        if(tot == k) {
          cout << res << '\n';
        } else {
          if(zero == 0) {
            res = (res * pos[pos.size() - 1]) % MOD;
            res = (res * neg[neg.size() - 1] * (-1LL)) % MOD;
            if(res < 0)
              res = (res + MOD) % MOD;
            cout << res << '\n';
          } else {
            cout << 0 << '\n';
          }
        }
      } else {
        if(zero == 0) {
          ll res = 1;
          for(int i = (int)neg.size() - 1; i >= (int)neg.size() - k; i--) {
            res = (res * neg[i]) % MOD;
          }
          res = (MOD - res) % MOD;
          if(res < 0)
            res = (res + MOD) % MOD;
          cout << res << '\n';
        } else {
          cout << 0 << '\n';
        }
      }
    }
  }

  return 0;
}
