#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

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

ll euler_phi(ll x) {
  ll temp = x, ret = x;
  for(ll i = 2; i * i <= temp; i++) {
    if(temp % i == 0) {
      ret -= ret / i;
      while(temp % i == 0) {
        temp /= i;
      } 
    }
  }
  if(temp > 1)
    ret -= ret / temp;
  return ret;
}

ll modpow(ll a, ll b, ll mod) {
  ll ret = 1;
  while(b) {
    if(b & 1) {ret = (ret * a) % mod;}
    a = (a * a) % mod;
    b >>= 1;
  }
  return ret;
}

ll order10(ll x) {
  ll phi = euler_phi(x);
  vector<ll> candidates = divisor(phi);
  sort(candidates.begin(), candidates.end());
  for(ll i : candidates) {
    if(modpow(10, i, x) == 1) {
      return i;
    }
  }
  return -1;
}

ll solve() {
  ll a, b;
  cin >> a >> b;
  a = abs(a);
  b = abs(b);
  ll lol = __gcd(a, b);
  a /= lol;
  b /= lol;
  a %= b;
  while(b % 2 == 0) {
    b /= 2;
  }
  while(b % 5 == 0) {
    b /= 5;
  }
  if(a == 0 || b == 1) {
    return 0;
  }
  ll ord = order10(b);
  return ord;
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