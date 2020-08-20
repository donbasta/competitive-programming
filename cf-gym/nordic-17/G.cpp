#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds; 
using piii = pair<pair<int, int>, int>;
using Tree = tree<piii, null_type, less<piii>, rb_tree_tag,tree_order_statistics_node_update>;

int n, m;
void solve() {
  Tree pbds;
  cin >> n >> m;
  vector<int> skor(n + 1), pen(n + 1);
  for(int i = 1; i <= n; i++) {
    pbds.insert(make_pair(make_pair(skor[i], pen[i]), i));
  }
  for(int i = 0; i < m; i++) {
    int ti, pe;
    cin >> ti >> pe;
    pbds.erase(pbds.find(make_pair(make_pair(skor[ti], pen[ti]), ti)));
    skor[ti]--;
    pen[ti] += pe;
    pbds.insert(make_pair(make_pair(skor[ti], pen[ti]), ti));
    int now = pbds.order_of_key(make_pair(make_pair(skor[1], pen[1]), 1));
    cout << now + 1 << '\n';
  }
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