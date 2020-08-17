#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, q;

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << (1LL << (2 * j)) << ' ';
    }
    cout << '\n';
  }
  cout << endl;
  cin >> q;
  while(q--) {
    ll k;
    cin >> k;
    ll mn = ((1LL << (2 * n)) - 1) / 3;
    // assert(k >= mn);
    k -= mn;
    // vector<ll> koefBit(2 * n + 2, 0);
    ll now = 0;
    // for(int i = 0; i <= n; i++) {
    //   if((k >> i) & 1) {
    //     koefBit[i]++;
    //     now++;
    //   }
    // }
    vector<ll> temp;
    while(k > 0) {
      now += (k % 4);
      temp.push_back(k % 4);
      k /= 4;
    }
    // cerr << now << 
    // reverse(temp.begin(), temp.end());
    temp.resize(2 * n + 2);
    vector<ll> koefBit = temp;
    for(int i = 2 * n + 1; i >= 0; i--) {
      if(now >= n - 1) break;
      if(koefBit[i] == 0) continue;
      ll cur = koefBit[i];
      // if(i & 1) {
      //   now += 3 * koefBit[i];
      //   koefBit[i - 1] += 3 * koefBit[i];
      //   koefBit[i] = 0;
      //   continue;
      // }      
      if(now + 3 * cur < n - 1) {
        koefBit[i - 1] += 4 * koefBit[i];
        koefBit[i] = 0;
        now += 3 * cur;
      } else {
        ll need = n - 1 - now;
        assert(need % 3 == 0);
        koefBit[i] -= need / 3;
        // assert(koefBit[i] == 0);
        koefBit[i - 1] += 4 * (need / 3);
        now = n - 1;
      }
    }
    // cerr << now << ":D\n";
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