#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> ar(2, vector<int>(n + 1));
  vector<int> pos[n + 1];
  vector<int> cnt(n + 1, 0);
  vector<bool> vis(n + 1, 0);

  for(int i = 0; i < 2; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> ar[i][j];
      cnt[ar[i][j]]++;
      pos[ar[i][j]].push_back(j);
    }
  }
  bool ok = true;
  for(int i = 1; i <= n; i++) {
    ok &= (cnt[i] == 2);
  }
  if(!ok) {
    cout << -1 << '\n'; return;
  }
  vector<int> ans;
  for(int i = 1; i <= n; i++) {
    if(vis[i]) continue;
    if(ar[0][i] == ar[1][i]) continue;
    vector<pair<int, bool>> temp;
    int rev = 0;
    int cur = i, p = ar[0][cur], q = ar[1][cur];
    int next = pos[q][0] + pos[q][1] - cur;
    temp.emplace_back(cur, 0);
    vis[cur] = true;
    while(next != i) {
      int last = q;
      bool isRev = false;
      cur = next, p = ar[0][cur], q = ar[1][cur];
      if(last == q) {swap(p, q); rev++; isRev = true;} 
      next = pos[q][0] + pos[q][1] - cur;
      temp.emplace_back(cur, isRev);
      vis[cur] = true;
    }
    bool cek = false;
    if(rev < (int)temp.size() - rev) {
      cek = true;
    }
    for(auto t : temp) {
      if(t.second == cek) ans.push_back(t.first);
    }
  }
  cout << (int)ans.size() << '\n';
  for(auto i : ans) cout << i << ' ';
  cout << '\n';
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