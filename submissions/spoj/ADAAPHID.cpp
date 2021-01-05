#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

typedef struct item* pitem;
struct item {
  ll id1, id2;
  ll sum;
  pitem l, r;
}

ll sum (pitem it) {
  return it ? it->sum : 0;
}

void upd_sum (pitem it) {
  if (it) {
    it->sum = sum (it->l) + sum (it->r) + it->id2;
  }
}

void split (pitem t, pitem& l, pitem& r, int key, int add = 0) {
  if (!t) {
    return
  } 
  int 
}

void merge (pitem& t, pitem l, pitem r) {
  if (!l || !r) {
    t = l ? l : r;
  } else if (l->)
}

void insert ()

ll get (pitem t, ll key) {

}

void solve() {
  cin >> Q;
  ll L = 0;
  pitem T;
  while (Q--) {
    ll A, V, id1, id2, rnd;
    cin >> A >> V;
    id1 = A ^ L;
    rnd = V ^ L;
    id2 = rnd + get (T, id1);
    L = id2;
    cout << id1 << ' ' << id2 << '\n';
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