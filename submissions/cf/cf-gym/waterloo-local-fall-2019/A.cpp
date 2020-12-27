#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  set<int> ans;
  int K;
  cin >> K;
  for(int i = 1; i * i <= K; i++) {
    if(K % i != 0) continue;
    int ii = K / i;
    if(i == ii) continue;
    int lol = ii - i;
    if(lol & 1) continue;
    ans.insert(lol / 2);
  }
  cout << (int)ans.size() << ''
  for(auto i : ans) {
    cout << i << ' ';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  // cin >> TC;
  for(int i = 1; i <= TC; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  
  return 0;
}