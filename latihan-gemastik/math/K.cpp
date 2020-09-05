#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int BIT = 64;
const ll INF = 1e18;
const int N = 1e5;

ll ar[N + 5];

void solve() {
  int n;
  cin >> n;
  ll idx = 0;
  for(int i = 0; i < n; i++) { cin >> ar[i]; }
  for(int i = BIT - 1; i >= 0; i--) {
    ll mxIdx = idx, mxVal = -INF;
    for(int j = idx; j < n; j++) {
      if((ar[j] & (1LL << i)) && (ar[j] > mxVal)) {
        mxVal = ar[j], mxIdx = j;
      }
    }
    if(mxVal == -INF) continue;
    swap(ar[idx], ar[mxIdx]);
    mxIdx = idx;
    for(int j = 0; j < n; j++) {
      if((j != mxIdx) && (ar[j] & (1LL << i))) {
        ar[j] ^= ar[mxIdx];
      }
    }
    idx++;
  }
  ll ans = 0;
  for(int i = 0; i < n; i++) {
    ans ^= ar[i];
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