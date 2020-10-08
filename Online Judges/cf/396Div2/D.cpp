#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e5 + 69;

int sz[N << 1], par[N << 1];
int n, m, q;
unordered_map<string, int> mp;

void init() {
  for(int i = 1; i <= 2 * n; i++) {
    sz[i] = 1;
    par[i] = i;
  }
}

int fpar(int a) {
  return (par[a] == a ? a : par[a] = fpar(par[a]));
}

void merge(int a, int b) {
  int aa, bb;
  aa = fpar(a);
  bb = fpar(b);
  if(aa == bb)
    return;
  if(sz[aa] < sz[bb])
    swap(aa, bb);
  sz[aa] += sz[bb];
  par[bb] = aa;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n >> m >> q;
  init();
  for(int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    mp[s] = 2 * i - 1;
  }
  for(int i = 1; i <= m; i++) {
    int t, ap, bp, aq, bq;
    string a, b;
    cin >> t >> a >> b;
    ap = fpar(mp[a]); bp = fpar(mp[b]);
    aq = fpar(mp[a] + 1); bq = fpar(mp[b] + 1);
    if(t == 1) {
      if(ap == bq || aq == bp) {
        cout << "NO" << '\n';
        continue;
      }
      cout << "YES" << '\n';
      merge(ap, bp);
      merge(aq, bq);
    } else if(t == 2) {
      if(ap == bp || aq == bq) {
        cout << "NO" << '\n';
        continue;
      }
      cout << "YES" << '\n';
      merge(ap, bq);
      merge(aq, bp);
    }
  }
  for(int i = 1; i <= q; i++) {
    int ap, bp, aq, bq;
    string a, b;
    cin >> a >> b;
    ap = fpar(mp[a]); bp = fpar(mp[b]);
    aq = fpar(mp[a] + 1); bq = fpar(mp[b] + 1);
    if(ap == bp || aq == bq)
      cout << 1;
    else if(ap == bq || aq == bp)
      cout << 2;
    else
      cout << 3;
    cout << '\n';
  }
  return 0;
}
