#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int n;

void solve() {
  cin >> n;
  vector<string> gr(n);
  for(int i = 0; i < n; i++) {
    cin >> gr[i];
  }
  vector<pair<int, int>> ans;
  if(gr[0][1] == gr[1][0]) {
    char c = gr[0][1];
    if(gr[n-1][n-2] == c) ans.emplace_back(n-1, n-2);
    if(gr[n-2][n-1] == c) ans.emplace_back(n-2, n-1);
  } else if(gr[n-2][n-1] == gr[n-1][n-2]) {
    char c = gr[n-2][n-1];
    if(gr[0][1] == c) ans.emplace_back(0, 1);
    if(gr[1][0] == c) ans.emplace_back(1, 0);
  } else {
    if(gr[n-1][n-2] == '1') ans.emplace_back(n-1, n-2);
    if(gr[n-2][n-1] == '1') ans.emplace_back(n-2, n-1);
    if(gr[0][1] == '0') ans.emplace_back(0, 1);
    if(gr[1][0] == '0') ans.emplace_back(1, 0);
  }
  cout << (int)ans.size() << '\n';
  for(auto& pos : ans) {
    cout << pos.first + 1 << ' ' << pos.second + 1 << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}