#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int n, k;
vector<int> ve;

bool cek(int a) {
  int len = 0;
  for(int i = 0; i < 2; i++) {
    int cur = 1, j = 1, temp = 0;
    while(j <= n) {
      if(temp % 2 == i % 2) {
        while(j <= n && ve[j] > a) {
          j++;
        }
        if(j > n)
          break;
      }
      j++;
      temp++;
    }
    len = max(len, temp);
  }
  return len >= k;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n >> k;
  ve.resize(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> ve[i];
  }
  int mx = 1e9, mn = 1, ans = -1;
  while(mx >= mn) {
    int mid = (mx + mn) / 2;
    if(cek(mid)) {
      ans = mid;
      mx = mid - 1;
    } else {
      mn = mid + 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
