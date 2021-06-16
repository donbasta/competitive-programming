#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int t;
  cin >> t;
  while(t--) {
    int n, k;
    ll ans = 0;
    cin >> n >> k;
    vector<int> ar(n), we(k);
    for(int i = 0; i < n; i++) {
      cin >> ar[i];
    }
    for(int i = 0; i < k; i++) {
      cin >> we[i];
    }
    sort(ar.begin(), ar.end());
    for(int i = n - 1; i >= n - k; i--) {
      ans += 1LL * ar[i];
    }
    sort(we.begin(), we.end(), greater<int>());
    int cur = 0;
    int curH = n - 1;
    for(int i = 0; i < k; i++) {
      if(we[i] == 1) {
        ans += 1LL * ar[curH];
        curH--;
        continue;
      }
      ans += 1LL * ar[cur];
      cur += we[i] - 1;
    }  
    cout << ans << '\n';
  }
  return 0;
}
