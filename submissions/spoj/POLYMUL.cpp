#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using cd = complex<long double>;

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
    for(auto x : a) {
      x /= n;
    }
  }
}

vector<int> mul(vector<int> const& a, vector<int> const& b) {
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
  vector<int> ret(n);
  for(int i = 0; i < n; i++) {
    ret[i] = round(fa[i].real());
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc;
  cin >> tc;
  while(tc--) {
    int n;
    cin >> n;
    vector<int> a, b;
    for(int i = 0; i <= n; i++) {
      int x;
      cin >> x;
      a.emplace_back(x);
    }
    for(int i = 0; i <= n; i++) {
      int x;
      cin >> x;
      b.emplace_back(x);
    }
    vector<int> res = mul(a, b);
    for(int i = 0; i <= 2 * n; i++) {
      cout << res[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
