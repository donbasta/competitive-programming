#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

using cd = complex<long double>;
const long double PI = acos(-1);
const int M = 2e5;

int res[5 * M + 10], ans[5 * M + 10];

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

void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<cd> PA(x + 1), PB(x + 1);
  for(int i = 0; i <= n; i++) {
    int lol;
    cin >> lol;
    PA[lol] = cd(1);
    PB[x - lol] = cd(1);
  }
  vector<cd> prod = mul(PA, PB);
  for(int i = x; i < (int)prod.size(); i++) {
    int cek = round(prod[i].real());
    if(cek > 0) res[i - x] = 1;
  }
  for(int i = 1; i <= 5 * M; i++) {
    if(res[i] == 0) continue;
    int ni = i + y;
    for(int j = ni; j <= 5 * M; j += ni) {
      ans[j] = max(ans[j], ni);
    }
  }
  int q;
  cin >> q;
  while(q--) {
    int l;
    cin >> l;
    if(ans[l / 2] == 0) cout << -1;
    else cout << 2 * ans[l / 2];
    cout << ' ';
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