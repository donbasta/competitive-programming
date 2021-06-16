#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> ar(n);
  set<pair<int, int>> se;
  vector<pair<int, int>> pa(n);
  for(int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  sort(ar.begin(), ar.end());
  for(int i = 0; i < n; i++) {
    pa[i] = make_pair(i + (x + ar[i] - 1) / ar[i], i);
    se.insert(pa[i]);
  }
  int ans = 0, curSmallest = 0;

  while(!se.empty()) {
    auto now = *se.begin();
    int q = now.first;
    if(q > n) break;
    for(int i = curSmallest; i < q; i++) {
      se.erase(pa[i]);
    }
    curSmallest = q;
    ans++;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  
  return 0;
}