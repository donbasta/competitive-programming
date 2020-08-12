#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  unordered_map<pair<int, int>, int> mp;
  for(int i = 1; i <= TC; i++) {
    cout << "Case #" << i << ": ";
    // solve();
    mp[i] = i;
    cout << mp[i] << '\n';
  }
  
  return 0;
}