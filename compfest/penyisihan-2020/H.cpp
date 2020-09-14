#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int M = 2e5;
const int MOD = 1000002359;
const int base = 181;
const int INF = 2e9;

int pw[M + 5];

inline void init_base() {
  pw[0] = 1;
  for(int i = 1; i <= M; i++) {
    pw[i] = (1LL * pw[i - 1] * base) % MOD;
  }
}

inline int get_hash(const string& S) {
  int ret = 0;
  for(int i = 0; i < (int)S.length(); i++) {
    int cur = S[i] - 'a' + 1;
    ret = (1LL * ret + 1LL * pw[i] * cur) % MOD;
  }
  return ret;
}

int pre[M + 5];
vector<string> kata;
unordered_map<int, bool> mp;

struct Node {
  bool ns;
  int l, r;
  int len_l, len_r;
  int count;
  Node(int l = 0, int r = 0, int len_l = 0, int len_r = 0, int count = 0, bool ns = 0) : l(l), r(r), len_l(len_l), len_r(len_r), count(count), ns(ns) {}
};

Node merge(const Node& a, const Node& b) {
  int temp_mid, len_mid;
  int l, r, len_l, len_r, count;
  bool ns;
  count = a.count + b.count;
  if(a.len_r > 0 && b.len_l > 0) { //merge mereka
    temp_mid = (1LL * a.r + 1LL * pw[a.len_r] * b.l) % MOD;
    if(temp_mid < 0) temp_mid += MOD;
    len_mid = a.len_r + b.len_l;
    int change = 0;
    if(mp.count(a.r)) { change--; }
    if(mp.count(b.l)) { change--; }
    if(mp.count(temp_mid)) { change++; }
    count += change;
  }
  l = a.l, len_l = a.len_l;
  r = b.r, len_r = b.len_r;
  if(a.len_l > 0 && a.ns && b.len_l > 0) { l = temp_mid, len_l = len_mid; }
  if(b.len_r > 0 && b.ns && a.len_r > 0) { r = temp_mid, len_r = len_mid; }
  ns = a.ns & b.ns;
  return Node(l, r, len_l, len_r, count, ns);
}

int m;
string st;

struct Segtree {
  vector<Node> t;
  Segtree(int n) { t.resize(4 * n + 5); }
  void build(int v, int s, int e) {
    if(s == e) {
      int cur = (st[s] == ' ' ? -1 : (st[s] - 'a' + 1));
      int len = (st[s] == ' ' ? -1 : 1);
      bool nospace = (st[s] == ' ' ? 0 : 1);
      t[v] = Node(cur, cur, len, len, mp.count(cur), nospace);
      return;
    }
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
    t[v] = merge(t[v << 1], t[v << 1 | 1]);
  }
  void upd(int v, int s, int e, int pos, int val) {
    if(s == e) {
      t[v] = Node(val, val, 1, 1, mp.count(val), 1);
      return;
    }
    int mid = (s + e) >> 1;
    if(pos <= mid) { upd(v << 1, s, mid, pos, val); } 
    else { upd(v << 1 | 1, mid + 1, e, pos, val); }
    t[v] = merge(t[v << 1], t[v << 1 | 1]);
  }
  Node que(int v, int s, int e, int l, int r) {
    if(l <= s && r >= e) { return t[v]; }
    int mid = (s + e) >> 1;
    if(l >= mid + 1) return que(v << 1 | 1, mid + 1, e, l, r);
    if(r <= mid) return que(v << 1, s, mid, l, r);
    Node ret = merge(que(v << 1, s, mid, l, min(r, mid)), que(v << 1 | 1, mid + 1, e, max(l, mid + 1), r));
    return ret;
  }
};

inline void solve() {

  init_base();

  cin >> m;
  cin.ignore();
  getline(cin, st);
  int sz = (int)st.size();

  string temp = "";
  for(int i = 0; i < sz; i++) {
    if(st[i] == ' ') {
      kata.push_back(temp);
      temp = "";
    } else {
      temp.push_back(st[i]);
    }
  }
  kata.push_back(temp);
  assert((int)kata.size() == m);

  for(int i = 1; i <= m; i++) {
    pre[i] = pre[i - 1] + (int)kata[i - 1].length();
    if(i > 1) pre[i]++;
  }

  int n, q;
  cin >> n >> q;
  while(n--) {
    string t;
    cin >> t;
    mp[get_hash(t)] = 1;
  }

  Segtree tree = Segtree(sz);
  tree.build(1, 0, sz - 1);
  while(q--) {
    int tipe;
    cin >> tipe;
    if(tipe == 0) {
      int i, j;
      char c;
      cin >> i >> j >> c;
      int lol = pre[i] - (int)kata[i - 1].length() + j;
      --lol;
      tree.upd(1, 0, sz - 1, lol, (int)(c - 'a' + 1));
    } else if(tipe == 1) {
      int a, b;
      cin >> a >> b;
      --a, --b;
      cout << tree.que(1, 0, sz - 1, a, b).count << '\n';
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