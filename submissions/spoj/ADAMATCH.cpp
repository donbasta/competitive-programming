#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

// const int mod = 998244353;
// const int root = 646;
// const int root_l = powmod(root, mod - 2);
// const int root_pw = 1 << 20;

const int mod = 7340033;
const int root = 5;
const int root_1 = 4404020;
const int root_pw = 1 << 20;

int powmod(int a, int b) {
  int ret = 1;
  while(b) {
    ret = 1LL * ret * a % mod;
    if(b & 1) {a = 1LL * a * a % mod;}
    b >>= 1;
  }
  return ret;
}

void fft(vector<int> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % mod);

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int)(1LL * w * wlen % mod);
            }
        }
    }

    if (invert) {
        int n_1 = powmod(n, mod-2);
        for (int & x : a)
            x = (int)(1LL * x * n_1 % mod);
    }
}

vector<int> mul(vector<int> const& a, vector<int> const& b) {
  vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;
  while(n < (int)a.size() + b.size()) {
    n <<= 1;
  }
  fa.resize(n);
  fb.resize(n);
  fft(fa, false);
  fft(fb, false);
  for(int i = 0; i < n; i++) {
    fa[i] = 1ll * fa[i] * fb[i] % mod;
  }
  fft(fa, true);
  return fa;
}

void solve() {
  map<char, int> POS;
  POS['A'] = 0; POS['C'] = 1; POS['G'] = 2; POS['T'] = 3;
  string s, r;
  cin >> s >> r;
  int ls = (int)s.length(), lr = (int)r.length();
  vector<int> tot(ls - lr + 1, 0);
  for(int now = 0; now < 4; now++) {
    vector<int> S, R;
    for(int i = 0; i < (int)s.length(); i++) {
      if(POS[s[i]] == now) {S.push_back(1);}
      else {S.push_back(0);}
    }
    for(int i = 0; i < (int)r.length(); i++) {
      if(POS[r[i]] == now) {R.push_back(1);}
      else {R.push_back(0);}
    }
    reverse(R.begin(), R.end());
    for(auto i : S) {cerr << i << ' ';}
    cerr << '\n';
    for(auto i : R) {cerr << i << ' ';}
    vector<int> SR = mul(S, R);
    cerr << (int)SR.size() << "lol";
    for(auto i : SR) {
      cerr << i << ' ';
      // cerr << powmod(i, mod - 2) << '\n';
    }
    for(int i = lr - 1; i < ls; i++) {
      tot[i - lr + 1] += SR[i];
    }
  }
  int maxMatch = -1;
  for(int i = 0; i <= ls - lr; i++) {
    maxMatch = max(maxMatch, tot[i]);
  }
  cout << lr - maxMatch << '\n';
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