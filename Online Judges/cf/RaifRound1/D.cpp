#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;

  vector<int> ar(n + 1);
  vector<int> ve[4];
  vector<pair<int, int>> ans;
  vector<int> row1(n + 1);

  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
    ve[ar[i]].push_back(i);
  }

  int row = n;
  for(int i : ve[1]) {
    ans.emplace_back(row, i);
    row1[i] = row;
    row--;
  }

  int idx = 0;
  int sz1 = (int) ve[1].size();
  vector<bool> nope(n + 1, 0);
  for(int i : ve[2]) {
    while(idx < sz1 && ve[1][idx] < i) {
      idx++;
    }
    if(idx == sz1) {
      cout << -1 << '\n';
      return;
    }
    ans.emplace_back(row1[ve[1][idx]], i);
    nope[ve[1][idx]] = 1;
    idx++;
  }

  vector<pair<int, int>> sisa;
  for(int i = 1; i <= n; i++) {
    if(ar[i] == 3) sisa.emplace_back(i, 3);
    if(ar[i] == 2) sisa.emplace_back(i, 2);
    if(ar[i] == 1 && !nope[i]) sisa.emplace_back(i, 1);
  }

  idx = 0;
  row = 1;
  int sz = (int)sisa.size();

  cerr << "lol";

  // for(auto& p : sisa) {
  //   cerr << p.first << ' ' << p.second << '\n';
  // }

  vector<int> temp;
  while(idx < sz) {
    if(sisa[idx].second == 3) 
      temp.push_back(sisa[idx].first);
    else {
      if(temp.empty()) {
        idx++;
        continue;
      }
      temp.push_back(sisa[idx].first);
      for(int i = 0; i < (int)temp.size() - 1; i++) {
        ans.emplace_back(row, temp[i]);
        ans.emplace_back(row, temp[i + 1]);
        row++;
      }
      temp.clear();
    }
    idx++;
  }

  if(!temp.empty()) {
    cout << -1 << '\n';
    return;
  }

  cout << (int)ans.size() << '\n';
  for(auto& pos : ans) {
    cout << pos.first << ' ' << pos.second << '\n';
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