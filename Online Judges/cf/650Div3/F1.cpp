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

  int tc;
  cin >> tc;
  while(tc--) {
    int n;
    cin >> n;
    vector<pair<int, int>> ve;
    for(int i = 0; i < n; i++) {
      int x;
      cin >> x;
      ve.emplace_back(x, i);
    }
    sort(ve.begin(), ve.end());
    int mx = 0, temp = 1;
    for(int i = 0; i < n - 1; i++) {
      if(ve[i + 1].second > ve[i].second)
        temp++;
      else {
        mx = max(temp, mx);
        temp = 1;
      }
    }
    mx = max(temp, mx);
    cout << n - mx << '\n';
  }
  return 0;
}
