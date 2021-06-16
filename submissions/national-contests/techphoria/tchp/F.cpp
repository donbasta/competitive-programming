#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll a, b, n, p, pp, bb;
ll fpb;
vector<ll> pw10_p, pw10_b, pw10_pp;

ll powmod(ll A, ll B, ll MOD) {
  ll ret = 1;
  while(B) {
    if(B & 1) { ret = ret * A % MOD; }
    A = A * A % MOD;
    B >>= 1;
  }
  return ret;
}

inline ll calc(int x) { return x * (x - 1) / 2; }

inline ll getFirstNDigit(ll k) {
  ll all, kk, num, den;

  all = (a * pw10_pp[k]);
  kk = (a * pw10_b[k]) % b;

  num = (((all - kk) % pp) + pp) % pp;
  den = bb;

  ll tt = pp / p;

  assert(num % (tt) == 0);
  num /= tt;

  ll ret = num * powmod(bb, p - 2, p) % p;
  if(ret < 0) ret += p;
  return ret;
}

inline void solve() {
  cin >> a >> b >> n >> p;
  fpb = __gcd(a, b);
  a /= fpb, b /= fpb;
  ll ans = 0;

  pw10_b.clear(), pw10_b.resize(n + 1);
  pw10_pp.clear(), pw10_pp.resize(n + 1);
  pw10_p.clear(), pw10_p.resize(n + 1);

  pp = p;
  bb = b;
  while(bb % p == 0) {
    pp *= p;
    bb /= p;
  }

  // cerr << pp << ' ' << b << '\n';

  ll temp_pp = 1, temp_b = 1, temp_p = 1;
  for(int i = 0; i <= n; i++) {
    pw10_pp[i] = temp_pp;
    temp_pp = (temp_pp * 10 % pp);
    pw10_b[i] = temp_b;
    temp_b = (temp_b * 10 % b);
    pw10_p[i] = temp_p;
    temp_p = (temp_p * 10 % p);
  }

  if(p != 5 && p != 2) {
    vector<ll> cnt(p, 0);
    cnt[0]++;
    for(int i = 1; i <= n; i++) {
      ll num = getFirstNDigit(i);
      num = (num * pw10_p[n - i]) % p;
      if(num < 0) num += p;
      cnt[num]++;
    }
    for(int i = 0; i < p; i++) {
      ans += calc(cnt[i]);
    }
    cout << ans << '\n';
  } else {
    for(int i = 1; i <= n; i++) {
      ll num = getFirstNDigit(i);
      if(num == 0) ans += i;
    }
    cout << ans << '\n';
  }
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}