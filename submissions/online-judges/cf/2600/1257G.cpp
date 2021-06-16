#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vll = vector<ll>;

const ld PI = acos(-1);
const ll mod = 998244353;
const ll root = 62;

void debug(vll A) {
  for (auto i : A) {
    cerr << i << ' ';
  }
  cerr << '\n';
} 

ll fpow (ll a, ll b) {
  ll ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}

inline ll inverse (ll a) { return fpow(a, mod - 2); }

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
  ll inv = inverse (n);
  for(int k = 2; k < n; k *= 2) {
    ll z[] = {1, fpow(root, curL /= 2)};
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

int n;
map<int, int> cnt;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> P;
vector<vll> ve;

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }

  int ctr = 0;
  for (auto pr : cnt) {
    int deg = pr.second;
    vll p(deg + 1, 1);
    ve.emplace_back(p);
    P.emplace(deg, ctr);
    ctr++;
  }

  while ((int) P.size() > 1) {
    auto ptr1 = P.top(); P.pop();
    auto ptr2 = P.top(); P.pop();
    vll p1 = ve[ptr1.second];
    vll p2 = ve[ptr2.second];
    // debug(p1);
    // debug(p2);
    vll prod = conv(p1, p2);
    // debug(prod);
    ve.emplace_back(prod);
    P.emplace(ptr1.first + ptr2.first, ctr);
    ctr++;
  }

  auto fin = P.top();
  if (fin.first < (n / 2)) {
    cout << 0 << '\n';
  } else {
    vll pfin = ve[fin.second];
    if ((int) pfin.size() < (n / 2)) {
      cout << 0 << '\n';
    } else {
      ll ret = pfin[n / 2];
      ret = (ret % mod);
      if (ret < 0) ret += mod;
      cout << ret << '\n';
    }
  }
  
  return;
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