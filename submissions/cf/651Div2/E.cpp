#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int n, one;
string s, t;
vector<int> ve;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n >> s >> t;
  for(int i = 0; i < n; i++) {
    if(s[i] == '1') one++;
    if(t[i] == '1') one--;
    if(s[i] == '1' && t[i] == '0') {
      ve.push_back(0);
    } else if(s[i] == '0' && t[i] == '1') {
      ve.push_back(1);
    }
  }
  if(one != 0) {
    cout << -1 << '\n';
    return 0;
  }
  int ans = 0, l0 = 0, l1 = 0;
  for(auto i : ve) {
    if(i == 0) {
      if(l1 == 0) {
        ans++;
      } else {
        l1--;
      }
      l0++;
    } else if(i == 1) {
      if(l0 == 0) {
        ans++;
      } else {
        l0--;
      }
      l1++;
    }
  }
  cout << ans << '\n';
  return 0;
}
