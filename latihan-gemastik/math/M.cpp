#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using cd = complex<ld>;

const ll MOD = 2e5 + 3;
const ll P_ROOT = 2; //primitive root
const ld PI = acos(-1);

ll pw[MOD + 5], ipw[MOD + 5];
 
void fft(vector<cd>& a, bool invert) {
  int n = (int)a.size();
  for(int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for(; j & bit; bit >>= 1) {
      j ^= bit;
    }
    j ^= bit;
    if(i < j) {
      swap(a[i], a[j]);
    }
  }
  for(int len = 2; len <= n; len <<= 1) {
    ld ang = 2 * PI / len * (invert ? -1 : 1);
    cd wlen(cos(ang), sin(ang));
    for(int i = 0; i < n; i += len) {
      cd w(1);
      for(int j = 0; j < len / 2; j++) {
        cd u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w *= wlen;
      }
    }
  }
  if(invert) {
    for(auto & x : a) {
      x /= n;
    }
  }
}
 
vector<cd> conv(vector<cd> const& a, vector<cd> const& b) {
  vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;
  while(n < (int)a.size() + b.size()) {
    n <<= 1;
  }
  fa.resize(n);
  fb.resize(n);
  fft(fa, false);
  fft(fb, false);
  for(int i = 0; i < n; i++) {
    fa[i] *= fb[i];
  }
  fft(fa, true);
  return fa;
}

void init() {
  ll temp = 1;
  ipw[temp] = 0;
  pw[0] = temp;
  for(int i = 1; i < MOD - 1; i++) {
    temp = (temp * P_ROOT) % MOD;
    ipw[temp] = i;
    pw[i] = temp;
  }
}

void solve() {
  init();
  int n;
  cin >> n;
  vector<int> A(MOD, 0);
  ll ans = 0;
  for(int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    if(x == 0) continue;
    ans = (ans - (x * x) % MOD);
    A[ipw[x]]++;
  }
  vector<cd> Ac(MOD);
  for(int i = 0; i < MOD; i++) {
    Ac[i] = cd(A[i]);
  }
  vector<cd> Sq = conv(Ac, Ac);
  int sz = (int)Sq.size();
  for(int i = 0; i < MOD - 1; i++) {
    ll temp = 0;
    if(i < sz) temp += (ll) roundl(Sq[i].real());
    if(i + MOD - 1 < sz) temp += (ll) roundl(Sq[i + MOD - 1].real());
    ans = (ans + temp * (pw[i]));
  }
  ans /= 2;
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