#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll m, n, fpb = 0;
map<ll, ll> mp;
bool ok = 0;

ll fastexpo(ll a, ll b) {
  ll ret = 1;
  while(b) {
    if(b & 1) { ret = ret * a; }
    a = a * a;
    b >>= 1;
  }
  return ret;
}

ll ans(ll t) {
  ll ret = 1;
  for(auto j : mp) {
    ret = ret * fastexpo(j.first, j.second * t / fpb);
  }
  return ret;
}

void solve() {
  cin >> m;
  if(m == 1) {
    cout << 1 << '\n';
    return;
  }
  for(ll i = 2; i * i <= m; i++) {
    if(m % i == 0) {
      ll cnt = 0;
      while(m % i == 0) { m /= i; cnt++; }
      mp[i] = cnt;
    }
  }
  if(m > 1) { mp[m]++; }
  for(auto i : mp) { mp[i.first] *= 2; }
  for(auto i : mp) {
    fpb = __gcd(fpb, i.second);
  }
  for(ll i = 1; i * i <= fpb; i++) {
    if(fpb % i != 0) continue;
    ll cur = i;
    ll cek = 1;
    for(auto j : mp) {
      ll temp = mp[j.first] * cur / fpb;
      cek *= (temp + 1);
    }
    if(cek == fpb / cur) { n = ans(cur); ok = 1; break; }
    if(i * i == fpb) continue;
    cur = fpb / i;
    cek = 1;
    for(auto j : mp) {
      ll temp = mp[j.first] * cur / fpb;
      cek *= (temp + 1);
    }
    if(cek == fpb / cur) { n = ans(cur); ok = 1; break; }
  }
  if(!ok) { cout << -1 << '\n'; }
  else { cout << n << '\n'; }
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