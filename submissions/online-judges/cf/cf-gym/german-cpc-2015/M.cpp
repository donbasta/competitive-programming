#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll fpb = a[0];
  for(int i = 0; i < n; i++) {
    fpb = __gcd(fpb, a[i]);
  }
  cin >> k;
  vector<ll> b(k);
  vector<bool> ans(k, 1);
  for(int i = 0; i < k; i++) {
    cin >> b[i];
    if(b[i] % fpb == 0) b[i] /= fpb;
    else ans[i] = 0;
  }
  if(a[0] == 1) {
    for(int i = 0; i < k; i++) {
      cout << "NIE" << '\n';
    }
    return;
  }
  for(int i = 0; i < n; i++) {
    a[i] /= fpb;
  }
  for(int i = 1; i < n; i++) {

  }


}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  
  return 0;
}