#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;

ll fastexpo(ll a, ll b) {
  ll ret = 1;
  while(b) {
    if(b & 1) {ret = (ret * a) % MOD;}
    a = (a * a) % MOD;
    b >>= 1;
  }
  if(ret < 0) ret += MOD;
  return ret;
}

void generate(ll curIdx, ll curDiv, const vector<pair<ll, ll>>& primes, vector<ll>& res) {
  if(curIdx == (ll)primes.size()) {
    res.push_back(curDiv);
    return;
  }
  for(ll i = 0; i <= primes[curIdx].first; i++) {
    generate(curIdx + 1, curDiv, primes, res);
    curDiv *= primes[curIdx].second;
  }
}
 
vector<ll> divisor(ll x) {
  vector<pair<ll, ll>> pr;
  vector<ll> res;
  ll temp = x;
  if(x == 1)
    return vector<ll>(1, 1);
  for(ll i = 2; i * i <= temp; i++) {
    if(temp % i == 0) {
      ll cnt = 0;
      while(temp % i == 0) {
        cnt++;
        temp /= i;
      }
      pr.emplace_back(cnt, i);
    }
  }
  if(temp > 1)
    pr.emplace_back(1, temp);
  generate(0, 1, pr, res);
  return res;
}

ll order4(ll x) {
  // ll phi = euler_phi(x);
  ll phi = x - 1;
  vector<ll> candidates = divisor(phi);
  sort(candidates.begin(), candidates.end());
  for(ll i : candidates) {
    if(fastexpo(4, i) == 1) {
      return i;
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  // int TC = 1;
  // cin >> TC;
  // for(int i = 1; i <= TC; i++) {
  //   cout << "Case #" << i << ": ";
  //   solve();
  // }
  // cout << order4(MOD) << ":D\n";
  cout << fastexpo(4, 269789058) << '\n';

  
  return 0;
}