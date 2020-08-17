#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, q;

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << (1LL << j) << ' ';
    }
    cout << '\n';
  }
  cout << endl;
  cin >> q;
  while(q--) {
    ll k;
    cin >> k;
    ll mn = (1LL << n) + n - 2;
    // assert(k >= mn);
    k -= ((1 << n) - 1);
    vector<ll> koefBit(2 * n, 0);
    ll now = 0;
    for(int i = 0; i < 2 * n; i++) {
      if((k >> i) & 1) {
        koefBit[i]++;
        now++;
      }
    }
    for(int i = 2 * n - 1; i >= 0; i--) {
      if(now >= n - 1) break;
      if(koefBit[i] == 0) continue;
      ll cur = koefBit[i];
      if(now + cur < n - 1) {
        koefBit[i - 1] += 2 * koefBit[i];
        koefBit[i] = 0;
        cur += now;
      } else {
        ll need = n - 1 - now;
        koefBit[i] -= need;
        koefBit[i - 1] += 2 * need;
        now = n - 1;
      }
    }
    ll x = 1, y = 1;
    for(int i = 0; i < n; i++) {
      cout << x << ' ' << y;
      cout << '\n';
      for(int j = 0; j < koefBit[i]; j++) {
        x++;
        cout << x << ' ' << y << '\n';
      }
      y++;
    }
    cout << endl << '\n';
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