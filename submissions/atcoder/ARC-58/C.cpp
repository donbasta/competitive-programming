#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int M = 10;

bool lol[M];

bool dislike(int x) {
  bool ret = false;
  while(x > 0) {
    int cur = x % 10;
    ret |= lol[cur];
    x /= 10;
  }
  return ret;
}

void solve() {
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < k; i++) {
    int d;
    cin >> d;
    lol[d] = true;
  }
  int ans = n;
  while(dislike(ans)) ans++;
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  // cin >> TC;
  for(int i = 1; i <= TC; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  
  return 0;
}