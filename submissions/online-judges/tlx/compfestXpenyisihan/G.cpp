#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e6;
int n, m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tc;
  cin >> tc;
  while(tc--) {
    cin >> n >> m;
    vector<int> cnt(N + 1, 0);
    for(int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      for(int j = 1; j * j <= x; j++) {
        if(x % j == 0) {
          cnt[j]++;
          if(j != x / j)
            cnt[x / j]++;
        }
      }
    }
    int ans = -1;
    for(int i = 1; i <= N; i++) {
      if(cnt[i] >= m) 
        ans = i;
    }
    cout << ans << '\n';
  }

  return 0;
}
