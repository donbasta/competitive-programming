#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

inline ll ceil(ll x, ll y) { return (x + y - 1) / y; }

const int N = 100;
const ll M = 5e4;
ll b[N + 5];

void solve() {
  int n;
  cin >> n;
  ll sum = 0;
  for(int i = 1; i <= n; i++) {
    cin >> b[i];
    sum += b[i];
  }
  if(n == 1) {
    if(b[1] == 0) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
    return;
  }
  if(sum % 3 != 0) {
    cout << "NO" << '\n';
    return;
  }

  ll l = ceil(b[1], 2), r = 2LL * b[1];
  // while((l + b[1]) % 3 != 0) ++l;
  if(l > r) {
    cout << "NO" << '\n';
    return;
  }
  for(int i = 2; i < n; i++) {
    ll nl = b[i] - r, nr = b[i] - l;
    if(nr < 0) {
      cout << "NO" << '\n';
      return;
    }
    nl = max(0LL, nl);
    l = ceil(nl, 2LL), r = 2LL * nr;
    // while((l + nl) % 3 != 0) ++l;
    if(l > r) {
      cout << "NO" << '\n';
      return;
    }
  }
  if(b[n] > r || b[n] < l) {
    cout << "NO" << '\n';
  } else {
    cout << "YES" << '\n';
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