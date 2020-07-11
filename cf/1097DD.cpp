#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

typedef vector<vector<int>> matrix;

const ll MOD = 1e9 + 7;

ll n;
int k, cnt = 0;
map<ll, int> mp;
vector<vector<ll>> ve;
vector<ll> di;
vector<int> lol;
vector<vector<int>> dp;
matrix magic, identity;

// void generate(int curIdx, ll curDiv, const vector<pair<int, ll>>& primes, vector<ll>& res) {
//   if(curIdx == (int)primes.size()) {
//     res.push_back(curDiv);
//     return;
//   }
//   for(int i = 0; i <= primes[curIdx].first; i++) {
//     generate(curIdx + 1, curDiv, primes, res);
//     curDiv *= primes[curIdx].second;
//   }
// }
 
vector<ll> factors(ll x) {
  // vector<pair<int, ll>> pr;
  // vector<ll> res;
  // ll temp = x;
  // if(x == 1)
  //   return vector<ll>(1, 1);
  // for(ll i = 2; i * i <= temp; i++) {
  //   if(temp % i == 0) {
  //     int cnt = 0;
  //     while(temp % i == 0) {
  //       cnt++;
  //       temp /= i;
  //     }
  //     pr.emplace_back(cnt, i);
  //   }
  // }
  // if(temp > 1)
  //   pr.emplace_back(1, temp);
  // generate(0, 1, pr, res);
  // return res;
  vector<ll> res;
  for(ll i = 1; i * i <= x; i++) {
    if(x % i == 0) {
      res.push_back(i);
      if(i != x / i)
        res.push_back(x / i);
    }
  }
  return res;
}

matrix mul(matrix a, matrix b, int sz){
  matrix d(sz, vector<int>(sz));
  for(int i = 0; i < sz; i++) {
    for(int j = 0; j < sz; j++) {
      for(int k = 0; k < sz; k++) {
        d[i][j] = (1LL * d[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;
      }
    }
  }
  return d;
}
 
matrix fast_expo(matrix a, ll b){
  int sz = (int) a.size();
  matrix ret = identity;
  while(b) {
    if(b & 1) {ret = mul(ret, a, sz);}
    a = mul(a, a, sz);
    b >>= 1;
  }
  return ret;
}

int modpow(int a, int b) {
  int ret = 1;
  while(b) {
    if(b & 1) ret = (1LL * ret * a) % MOD;
    a = (1LL * a * a) % MOD; 
    b >>= 1;
  }
  return ret;
}

int inv(int x) {
  return modpow(x, MOD - 2);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;
  di = factors(n);
  sort(di.begin(), di.end());
  ve.resize(di.size());
  lol.resize(di.size());
  for(auto i : di) {
    mp[i] = cnt++;
  }
  magic.assign(cnt, vector<int>(cnt, 0));
  identity.assign(cnt, vector<int>(cnt, 0));
  for(int i = 0; i < cnt; i++) identity[i][i] = 1;
  for(auto i : di) {
    vector<ll> temp;
    if(i == n) {
      temp = di;
    } else {
      temp = factors(i);
    }
    int cur = mp[i];
    lol[cur] = inv((int)temp.size());
    for(auto j : temp) {
      magic[cur][mp[j]] = lol[cur];
    }
  }
  magic = fast_expo(magic, k);
  ll ans = 0;
  for(auto j : di) {
    ans = (ans + 1LL * magic[cnt - 1][mp[j]] * (j % MOD)) % MOD;
  }
  if(ans < 0)
    ans += MOD;
  cout << ans << '\n';
  return 0;
}