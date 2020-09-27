#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e5;

int n, q;
int ar[N + 5];

struct Node {
  vector<int> ve, len;
  bool same;
  int mxlen;
  Node() {
    ve.resize(2), len.resize(2);
  }
  Node(int c) {
    ve.resize(2), len.resize(2);
    mxlen = 1;
    same = 1;
    ve[0] = ve[1] = c;
    len[0] = len[1] = 1;
  }
};

Node merge(const Node& l, const Node& r) {
  Node ret;
  ret.ve[0] = l.ve[0];
  ret.ve[1] = r.ve[1];
  if(l.same && r.same) {
    if(l.ve[1] == r.ve[0]) {
      ret.same = 1;
      ret.mxlen = l.mxlen + r.mxlen;
      ret.len[0] = (l.len[1] + r.len[0]);
      ret.len[1] = (l.len[1] + r.len[0]);
    } else {
      ret.same = 0;
      ret.mxlen = max(l.mxlen, r.mxlen);
      ret.len[0] = l.len[0];
      ret.len[1] = r.len[1];
    }
  } else if(l.same) {
    ret.same = 0;
    ret.len[1] = r.len[1];
    if(l.ve[1] == r.ve[0]) {
      ret.len[0] = l.len[1] + r.len[0];
      ret.mxlen = max(ret.len[0], r.mxlen);
    } else {
      ret.len[0] = l.len[0];
      ret.mxlen = max(r.mxlen, l.mxlen);
    }
  } else if(r.same) {
    ret.same = 0;
    ret.len[0] = l.len[0];
    if(l.ve[1] == r.ve[0]) {
      ret.len[1] = l.len[1] + r.len[0];
      ret.mxlen = max(ret.len[1], l.mxlen);
    } else {
      ret.len[1] = r.len[1];
      ret.mxlen = max(r.mxlen, l.mxlen);
    }
  } else {
    ret.same = 0;
    if(l.ve[1] == r.ve[0]) {
      ret.mxlen = max({l.mxlen, r.mxlen, l.len[1] + r.len[0]});
    } else {
      ret.mxlen = max(l.mxlen, r.mxlen);
    }
    ret.len[0] = l.len[0];
    ret.len[1] = r.len[1];
  }
  return ret;
}

struct Segtree {
  vector<Node> t;
  vector<bool> lz;
  Segtree(int n) {
    t.resize(4 * n + 5);
    lz.resize(4 * n + 5);
  }
  void build(int v, int s, int e) {
    if(s == e) {
      t[v] = Node(ar[s]);
      return;
    }
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
    pull(v);
  }
  void upd(int v, int s, int e, int l, int r) {
    if(l == s && r == e) {
      lz[v] = 1;
      t[v].ve[0] ^= 1;
      t[v].ve[1] ^= 1;
      return;
    }
    push(v);
    int mid = (s + e) >> 1;
    if(r <= mid) { upd(v << 1, s, mid, l, r); }
    else if(l >= mid + 1) { upd(v << 1 | 1, mid + 1, e, l, r); }
    else {
      upd(v << 1, s, mid, l, mid);
      upd(v << 1 | 1, mid + 1, e, mid + 1, r);
    }
    pull(v);
  }
  Node que(int v, int s, int e, int l, int r) {
    if(l == s && r == e) {
      return t[v];
    }
    push(v);
    int mid = (s + e) >> 1;
    if(r <= mid) { return que(v << 1, s, mid, l, r); }
    else if(l >= mid + 1) { return que(v << 1 | 1, mid + 1, e, l, r); }
    else {
      return merge(que(v << 1, s, mid, l, mid), que(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
  }
  void push(int v) {
    if(!lz[v]) return;
    lz[v << 1] = 1;
    lz[v << 1 | 1] = 1;
    for(int i = 0; i < 2; i++) {
      t[v << 1].ve[i] ^= 1;
      t[v << 1 | 1].ve[i] ^= 1;
    }
    lz[v] = 0;
  }
  void pull(int v) {
    t[v] = merge(t[v << 1], t[v << 1 | 1]);
  }
  void debug(int v, int s, int e) {
    if(s == e) {
      cerr << v << ' ' << s << ' ' << e << '\n';
      for(int i = 0; i < 2; i++) {
        cerr << t[v].ve[i] << ' ' << t[v].len[i] << '\n';
      }
      cerr << t[v].mxlen << ' ' << t[v].same << '\n';
      return;
    }
    int mid = (s + e) >> 1;
    push(v);
    debug(v << 1, s, mid);
    debug(v << 1 | 1, mid + 1, e);
    cerr << v << ' ' << s << ' ' << e << '\n';
    for(int i = 0; i < 2; i++) {
      cerr << t[v].ve[i] << ' ' << t[v].len[i] << '\n';
    }
    cerr << t[v].mxlen << ' ' << t[v].same << '\n';
  }
};

inline void solve() {
  cin >> n >> q;
  for(int i = 1; i <= n; i++) { 
    char c;
    cin >> c;
    ar[i] = (int) (c - '0'); 
  }

  Segtree Tree = Segtree(n + 1);
  Tree.build(1, 1, n);

  while(q--) {
    int te, l, r;
    cin >> te >> l >> r;
    if(te == 1) {
      Tree.upd(1, 1, n, l, r);
    } else {
      Node ans = Tree.que(1, 1, n, l, r);
      cout << ans.mxlen << '\n';
    }
  }

  Tree.debug(1, 1, n);

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