#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vll = vector<ll>;

const int N = 3e5;
const int mod = 998244353; 
const int root = 62;

ll fastexpo(ll a, ll b) {
  ll ret = 1;
  while(b) {
    if(b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}

void NTT(vll& a, vll& rt, vll& rev, int n) {
  for(int i = 0; i < n; i++){
    if(i < rev[i]) swap(a[i], a[rev[i]]);
  }
  for(int k = 1; k < n; k *= 2){
    for(int i = 0; i < n; i += 2 * k) {
      for(int j = 0; j < k; j++) {
        ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
        a[i + j + k] = (z > ai ? ai - z + mod : ai - z);
        ai += (ai + z >= mod ? z - mod : z);
      }
    }
  }
}

vll conv(const vll& a, const vll& b) {
  if(a.empty() || b.empty()) 
    return {};
  int s = (int)a.size() + (int)b.size() - 1;
  int B = 32 - __builtin_clz(s);
  int n = 1 << B;
  vll L(a), R(b), out(n), rt(n, 1), rev(n);
  L.resize(n), R.resize(n);
  for(int i = 0; i < n; i++) {
    rev[i] = (rev[i / 2] | (i & 1) << B) / 2;
  }
  ll curL = mod / 2;
  ll inv = fastexpo(n, mod - 2);
  for(int k = 2; k < n; k *= 2) {
    ll z[] = {1, fastexpo(root, curL /= 2)};
    for(int i = k; i < 2 * k; i++) {
      rt[i] = rt[i / 2] * z[i & 1] % mod;
    }
  }
  NTT(L, rt, rev, n); NTT(R, rt, rev, n);
  for(int i = 0; i < n; i++) {
    out[-i & (n - 1)] = L[i] * R[i] % mod * inv % mod;
  }
  NTT(out, rt, rev, n);
  return {out.begin(), out.begin() + s};
}

int cnt[N + 5], p[N + 5], q[N + 5];
ll pw[N + 5], fac[N + 5], ifac[N + 5];
int b[5];
vll poly[5];

void init() {
  pw[0] = 1;
  for(int i = 1; i <= N; i++) 
    pw[i] = pw[i - 1] * 2 % mod;
  fac[0] = 1;
  for(int i = 1; i <= N; i++)
    fac[i] = i * fac[i - 1] % mod;
  ifac[N] = fastexpo(fac[N], mod - 2);
  for(int i = N - 1; i >= 0; i--) 
    ifac[i] = ifac[i + 1] * (i + 1) % mod;
}

int C(int a, int b) {
  if(a < b || a < 0 || b < 0) return 0;
  int ret = fac[a];
  ret = ret * ifac[a - b] % mod;
  ret = ret * ifac[b] % mod;
  return ret;
}

void solve() {
  init();
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  for(int i = 1; i <= N; i++) {
    p[i] = p[i - 1] + (cnt[i] == 1);
    q[i] = q[i - 1] + (cnt[i] >= 2);
  }
  for(int i = 0; i < k; i++) {
    cin >> b[i];
  }
  for(int i = 0; i < k; i++) {
    int pp = p[b[i] - 1];
    int qq = q[b[i] - 1];
    vll P, Q;
    for(int i = 0; i <= pp; i++) {
      ll temp = pw[i] * C(pp, i) % mod;
      P.emplace_back(temp);
    }
    for(int i = 0; i <= qq * 2; i++) {
      ll temp = C(qq * 2, i);
      Q.emplace_back(temp);
    }
    poly[i] = conv(P, Q);
  }
  int q;
  cin >> q;
  while(q--) {
    int Q;
    cin >> Q;
    ll ret = 0;
    for(int i = 0; i < k; i++) {
      int loc = (Q / 2) - 1 - b[i];
      if(loc < 0 || loc >= (int)poly[i].size()) continue;
      ret = (ret + poly[i][loc]) % mod;
    }
    if(ret < 0) ret += mod;
    cout << ret << '\n';
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