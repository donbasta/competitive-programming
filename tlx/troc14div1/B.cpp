#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int M = 64;
const int N = 1e5;

ll ar[N + 5], pre[N + 5], suf[N + 5];

void solve() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
    pre[i] = pre[i - 1] ^ ar[i];
  }
  for(int i = n; i >= 1; i--) {
    suf[i] = suf[i + 1] ^ ar[i];
  }
  ll ans = pre[n];
  for(int i = 1; i <= n; i++) {
    ll now = pre[i - 1] ^ suf[i + 1];
    bool udah = 0;
    ll temp = 0;
    for(int j = M - 1; j >= 0; j--) {
      ll cur = (now & (1LL << j));
      ll cur2 = (ar[i] & (1LL << j));
      if(cur ^ cur2) { temp += (1LL << j); continue; }
      else {
        if(cur2) { udah = 1; temp += (1LL << j); }
        else if(!udah) { continue; }
        else { temp += (1LL << j); }
      }
    }
    ans = max(ans, temp);
  }
  cout << ans << '\n';
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