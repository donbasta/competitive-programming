#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

template<typename T> void inpos(T & x) {
  x = 0;
  register T c = getchar();
  while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
  bool neg = false;
  if (c == '-') neg = true;
  for (; c < 48 || c > 57; c = getchar());
  for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
  if (neg) x = -x;
}
 
template<typename T> void outpos(T n) {
  if (n < 0) {
    putchar('-');
    n *= -1;
  }
  char snum[65];
  int i = 0;
  do {
    snum[i++] = n % 10 + '0';
    n /= 10;
  } while (n);
  i = i - 1;
  while (i >= 0) putchar(snum[i--]);
  putchar('\n');
}

struct Line {
  mutable ll k, m, p;
  bool operator< (const Line& o) const { return k < o.k; }
  bool operator< (ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
  const ll inf = LLONG_MAX;
  ll div(ll a, ll b) {
    return a / b - ((a ^ b) < 0 && a % b);
  }
  bool isect(iterator x, iterator y) {
    if(y == end()) { x->p = inf; return false; }
    if(x->k == y->k) { x->p = (x->m > y->m) ? inf : -inf; }
    else { x->p = div(y->m - x->m, x->k - y->k); }
    return x->p >= y->p;
  }
  void add(ll k, ll m) {
    auto z = insert({k, m, 0}), y = z++, x = y;
    while(isect(y, z)) { z = erase(z); }
    if(x != begin() && isect(--x, y)) { isect(x, y = erase(y)); }
    while((y = x) != begin() && (--x)->p >= y->p) { isect(x, erase(y)); }    
  }
  bool query(ll x, ll& res) {
    if(empty()) { return false; }
    auto pl = lower_bound(x);
    if(pl == end()) --pl;
    auto l = *pl;
    res = l.k * x + l.m;
    return true;
  }
};

const int N = 3e5;

int n;
pair<ll, ll> qu[N + 5];
LineContainer cht;
map<pair<ll, ll>, int> cnt;

void solve() {
  inpos(n);
  for(int i = 1; i <= n; i++) {
    ll tp, a, b;
    inpos(tp);
    if(tp == 1) {
      inpos(a), inpos(b);
      qu[i] = make_pair(a, b);
      cnt[qu[i]]++;
      cht.add(a, b);
    } else if(tp == 2) {
      inpos(a);
      auto t = cht.lower_bound({qu[a].first, qu[a].second, -LLONG_MAX});
      if((t->k != qu[a].first) && (t->m != qu[a].second)) continue;
      cnt[qu[a]]--;
      if(cnt[qu[a]] == 0) cht.erase(t);
    } else if(tp == 3) {
      inpos(a);
      ll ans;
      if(cht.query(a, ans)) { outpos(ans); }
      else { printf("EMPTY SET\n"); }
    }
  }
}

int main() {

  int TC = 1;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}