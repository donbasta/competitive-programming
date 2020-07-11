#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tc;
  cin >> tc;
  while(tc--) {
    int n;
    cin >> n;
    set<int> se;
    vector<bool> lol(n + 1, false);
    vector<int> res;
    for(int i = 1; i <= n; i++) {
      cin >> ar[i];
      ve.emplace_back(ar[i], i);
      se.insert(ar[i]);
      lol[ar[i]] = true;
    }
    sort(ve.begin(), ve.end());
    reverse(ve.begin(), ve.end());
    int cur = 0;
    for(int i = 0; i < n; i++) {
      if(!lol[i]) {
        res.push_back(ve[cur].second);
        ar[ve[cur].second] = i;
        lol[i] = true;
      }
    }

  }

  return 0;
}
