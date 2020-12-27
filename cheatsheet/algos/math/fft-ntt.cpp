const int mod = 998244353;
const int root = 646;
const int invRoot = binpow(root, mod - 2);
const int root_pw = 1 << 20;

// const int mod = 7340033;
// const int root = 5;
// const int root_1 = 4404020;
// const int root_pw = 1 << 20;

void fft(vector<int> & a, bool invert) {
  int n = (int) a.size();
  for (int i=1, j=0; i<n; i++) {
    int bit = n >> 1;
    for (; j >= bit; bit >>= 1) j -= bit;
    j += bit;
    if (i < j) swap(a[i], a[j]);
  }

  for (int len = 2; len <= n; len <<= 1) {
    int wlen = invert ? root_1 : root;
    for (int i = len; i < root_pw; i <<= 1)
      wlen = (int) (wlen * 1ll * wlen % mod);
    for (int i = 0; i < n; i += len) {
      int w = 1;
      for (int j = 0; j < len / 2; j++) {
        int u = a[i+j], v = (int) ( a[i+j+len/2] * 1ll * w % mod);
        a[i+j] = u+v<mod ? u+v : u+v-mod;
        a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
        w = int (w * 1LL * wlen % mod);
      }
    }
  }

  if (invert) {
    int n_1 = powmod(n, mod-2);
    for (int i=0; i<n; ++i) a[i] = int (a[i] * 1ll * n_1 % mod);
  }
}

void squaring(vector<int> & a){
  int n1 = 2*a.size(), lg = 0;
  while ((1<<lg) < n1) 
    ++lg;
  n1 = 1<<lg;
  a.resize(n1,0);
  fft(a,false);
  for(int i=0; i<n1; ++i) 
    a[i] = 1LL * a[i] * a[i] % mod;
  fft(a, true);
  while(n1>1 && a[n1-1]==0) 
    --n1;
  a.resize(n1);
}

vector<int> multiply(vector<int> & a, vector<int> & b) {
  int n1 = a.size() + b.size(), lg = 0;
  while ((1<<lg) < n1) 
    ++lg;
  n1 = 1<<lg;
  a.resize(n1,0);
  b.resize(n1,0);
  fft(a, false);
  fft(b, false);
  vector<int> res(n1);
  for (int i = 0; i < n1; i++) 
    res[i] = 1LL * a[i] * b[i] % mod;
  fft(res, true);
  while(n1>1 && res[n1-1]==0) 
    --n1;
  res.resize(n1);
  return res;
}
 
vector<int> fast_expo(vector<int> & a, int m){
  if(m==0) return {1};
  if(m==1) return a;
  vector<int> c = a;
  vector<int> b = fast_expo(a, m/2);
  squaring(b);
  if(m&1) b = multiply(b,c);
  return b;
}