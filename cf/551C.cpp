#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e5 + 69;

int n, m, ar[N];
ll t;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  pair<int, int> cnt = make_pair(0, m);
  bool done = true;
  for(int i = 1; i <= n; i++) {
    t += 1LL;
    if(cnt.second <= ar[i]) {
      t += 1LL;
      ar[i] -= cnt.second;
      if(ar[i] != 0)
        done = false;
      if(cnt.second <= ar[i]) {
        int a = ar[i] / m;
        int b = ar[i] % m;
        t += 1LL * a;
        cnt = make_pair(b, m - b);
      } else {
        cnt = make_pair(ar[i] + cnt.first, cnt.second - ar[i]);
      }
    } else {
      if(ar[i] != 0)
        done = false;
      cnt = make_pair(ar[i] + cnt.first, cnt.second - ar[i]);
    }
    cerr << t << " uwu\n";
  }
  if(!done)
    t += 1LL;
  cout << t << '\n';
  return 0;
}
