#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 300, NMAX = 4e5;
vector<int> pr;

unordered_map<int, int> t[(NMAX << 2) + 5], lz[(NMAX << 2) + 5];
int n, q, primeSize;
int ar[NMAX + 5];
ll pw[70][70];

void init() {
  vector<bool> isPrime(N + 5, 1);
  for(int i = 2; i <= N; i++) {
    if(!isPrime[i]) continue;
    pr.push_back(i);
    for(int j = 2 * i; j <= N; j += i) {
      isPrime[j] = false;
    }
  }
  primeSize = (int)pr.size();
  for(int i = 0; i < (int)pr.size(); i++) {
    pw[i][0] = 1;
    ll temp = 1;
    int cur = 0;
    while(temp < LLONG_MAX / pr[i]) {
      temp = temp * pr[i];
      pw[i][++cur] = temp;
    }
  }
  // for(int i = 0; i < (NMAX << 2) + 5; i++) {
  //   t[i].resize(primeSize);
  //   lz[i].resize(primeSize);
  // }
}

void build(int v, int s, int e, int idx, const vector<int>& ve) {
  if(s == e) {t[v][idx] = ve[s]; return;}
  int mid = (s + e) >> 1;
  build(v << 1, s, mid, idx, ve);
  build(v << 1 | 1, mid + 1, e, idx, ve);
  t[v][idx] = t[v << 1][idx] + t[v << 1 | 1][idx];
}

void make() {
  for(int i = 0; i < (int)pr.size(); i++) {
    vector<int> temp(n + 1);
    for(int j = 1; j <= n; j++) {
      int now = ar[j];
      while(ar[j] % pr[i] == 0) {
        ar[j] /= pr[i], temp[j]++;
      }
    }
    build(1, 1, n, i, temp);
  }
}

void push(int v, int s, int e, int idx) {
  if(!lz[v][idx]) return;
  int mid = (s + e) >> 1;
  t[v << 1][idx] += (mid - s + 1) * lz[v][idx];
  t[v << 1 | 1][idx] += (e - mid) * lz[v][idx];
  lz[v << 1][idx] += lz[v][idx];
  lz[v << 1 | 1][idx] += lz[v][idx];
  lz[v][idx] = 0;
}

void upd(int v, int s, int e, int l, int r, int idx, int val) {
  if(l > e || r < s) return;
  if(l == s && r == e) {
    t[v][idx] += val * (e - s + 1);
    lz[v][idx] += val;
    return;
  }
  int mid = (s + e) >> 1;
  push(v, s, e, idx);
  upd(v << 1, s, mid, l, min(mid, r), idx, val);
  upd(v << 1 | 1, mid + 1, e, max(mid + 1, l), r, idx, val);
  t[v][idx] = t[v << 1][idx] + t[v << 1 | 1][idx];
}

void mul(int l, int r, int x) {
  for(int i = 0; i < (int)pr.size(); i++) {
    int temp = 0;
    while(x % pr[i] == 0) {
      x /= pr[i], temp++;
    }
    if(temp) upd(1, 1, n, l, r, i, temp);
  }
}

int que(int v, int s, int e, int l, int r, int idx) {
  if(l > e || r < s) return 0;
  if(l == s && r == e) {
    return t[v][idx];
  }
  int mid = (s + e) >> 1;
  push(v, s, e, idx);
  return que(v << 1, s, mid, l, min(r, mid), idx) + que(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, idx);
}

int tot(int l, int r) {
  ll ret = 1;
  for(int i = 0; i < (int)pr.size(); i++) {
    int temp = que(1, 1, n, l, r, i);
    if(temp > 0) {
      ret = ret * pw[i][temp - 1] * (pr[i] - 1);
    }
  }
  return ret;
}

void solve() {
  init();
  cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  make();
  while(q--) {
    string s;
    cin >> s;
    int l, r;
    if(s == "MULTIPLY") {
      int x;
      cin >> l >> r >> x;
      mul(l, r, x);
    } else if(s == "TOTIENT") {
      cin >> l >> r;
      cout << tot(l, r) << '\n';
    }
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