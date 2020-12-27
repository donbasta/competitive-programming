#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using cd = complex<long double>;

const ld PI = acos(-1);
const ld rt3 = 2.0 * PI / 3.0;

string s;

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

vector<cd> mul(vector<cd> const& a, vector<cd> const& b) {
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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> s;
  int sz = (int)s.length();
  vector<cd> a(sz), b(sz);
  for(int i = 0; i < sz; i++) {
  	ll temp = s[i] - 'a';
  	cd cur(cos(rt3 * temp), sin(rt3 * temp));
  	a[i] = cur;
  }
  for(int i = sz - 1; i >= 0; i--) {
  	ll temp = s[sz - 1 - i] - 'a';
  	cd cur(cos(rt3 * temp), sin((-1.0) * rt3 * temp));
  	b[i] = cur;
  }
  vector<cd> lol = mul(a, b);
  vector<ll> match(sz + 2);
  ll mx = -1;
  for(int i = sz; i < 2 * sz - 1; i++) {
  	ld koef = lol[i].real();
    
  	koef = ((koef * 2.0) + 2 * sz - i - 1) / 3.0;
    // cerr << fixed << setprecision(20) << koef << '\n';

  	ll temp = round(koef);
  	match[i - sz + 1] = temp;
  	mx = max(mx, temp);
  }
  cout << mx << '\n';
  for(int i = 1; i <= sz; i++) {
    cerr << i << ' ' << match[i] << '\n';
    if(match[i] == mx) {cout << i << ' ';}
  }
  return 0;
}