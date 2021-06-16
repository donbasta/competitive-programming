#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e6 + 3;

ll fastexpo(ll a, ll b, ll mod = MOD) {
  ll ret = 1;
  while(b) {
    if(b & 1) {ret = ret * a % MOD;}
    a = a * a % MOD;
    b >>= 1;
  }
  return ret;
}

ll inv(ll a, ll mod = MOD) {
  return fastexpo(a, mod - 2);
}

ll n, k;
ll a, aa, bb;

void solve() {
  cin >> n >> k;
  if(n < 64 && k > (1LL << n)) {
    cout << 1 << ' ' << 1 << '\n';
    return;
  }
  a = fastexpo(2, n);
  aa = fastexpo(a, k);
  if(k < MOD) {
    ll temp = 1;
    ll cur = (a - k + 1) % MOD;
    for(int i = 0; i < k; i++) {
      temp = temp * cur % MOD;
      cur = (cur + 1) % MOD;
    }
    aa = (aa - temp) % MOD;
  } 
  int lsb;
  int cnt = __builtin_popcountll(k);
  for(int i = 0; i < 70; i++) {
    if(k & (1LL << i)) {
      lsb = i; break;
    }
  }
  ll pw = fastexpo(2, k - 1 + n - lsb - cnt + 1);
  aa = aa * inv(pw) % MOD;
  bb = fastexpo(a, k) * inv(pw) % MOD;
  if(aa < 0) aa += MOD;
  if(bb < 0) bb += MOD;
  cout << aa << ' ' << bb << '\n';
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