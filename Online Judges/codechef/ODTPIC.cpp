#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MX = 4e3;
const int N = 1e5;

bitset<MX + 5> a[N + 5], b[N + 5];
int n, m, q;

void solve() {
  cin >> n >> m >> q;
  for(int i = 1; i <= n; i++) {
    int x; cin >> x;
    a[i] = a[i - 1];
    a[i].flip(x);
  }
  for(int i = 1; i <= m; i++) {
    int x; cin >> x;
    b[i] = b[i - 1];
    b[i].flip(x);
  }
  while(q--) {
    int l1, l2, r1, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    bitset<MX + 5> temp;
    temp = a[r1] ^ a[l1 - 1] ^ b[r2] ^ b[l2 - 1];
    cout << temp.count() << '\n';
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