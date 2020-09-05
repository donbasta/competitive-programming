#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using cd = complex<ld>;

const ld PI = acos(-1);
 
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

string s;

void solve() {
  cin >> s;
  int sz = (int)s.length();
  vector<cd> A(sz), B(sz);
  for(int i = 0; i < sz; i++) {
    if(s[i] == 'A') A[i] = cd(cos(PI / 2.), sin(PI / 2.));
    else A[i] = cd(1);
  }
  for(int i = 0; i < sz; i++) {
    if(s[i] == 'A') B[sz - 1 - i] = cd(cos(PI * 1.5), sin(PI * 1.5));
    else B[sz - 1 - i] = cd(1);
  }
  vector<cd> AB = conv(A, B);
  for(int i = 1; i < sz; i++) {
    cd lul = AB[sz - 1 + i];
    ll tot = sz - i;
    ll x = (ll) round(lul.real());
    ll y = (ll) round(lul.imag());
    ll ans = (tot - x + y) / 2;
    cout << ans << '\n';
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