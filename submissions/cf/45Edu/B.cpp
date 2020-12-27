#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e6;
int cnt[N + 5];

void solve() {
  int n, k;
  cin >> n >> k;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
    mx = max(mx, x);
  }
  int ans = 0;
  int last = mx;
  int last_max = mx;
  for (int i = mx - 1; i >= 1; i--) {
    if (cnt[i] == 0) continue;
    if (i + k < last) {
      ans += cnt[last_max];
      last_max = i;
    }
    last = i;
  }
  ans += cnt[last_max];
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