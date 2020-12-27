#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tc;
  cin >> tc;
  while(tc--) {
    int n, k;
    cin >> n >> k;
    vector<int> ve(n);
    for(int i = 0; i < n; i++) {
      cin >> ve[i];
    }
    sort(ve.begin(), ve.end());
    int mn = 1e9 + 1;
    for(int i = 0; i <= k; i++) {
      mn = min(mn, ve[i + n - k - 1] - ve[i]);
    }
    cout << mn << '\n';
  }
  
  return 0;
}