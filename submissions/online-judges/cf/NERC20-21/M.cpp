#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;
bool found;

void solve() {
  cin >> n;
  vector<int> ve, k(n);
  vector<vector<int>> se(n);
  map<int, int> pos;

  for (int i = 0; i < n; i++) {
    cin >> k[i];
    for (int j = 0; j < k[i]; j++) {
      int a;
      cin >> a;
      se[i].push_back(a);
      ve.push_back(a);
    }
  }
  sort(ve.begin(), ve.end());
  ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
  int sz = (int)ve.size();
  for (int i = 0; i < sz; i++) {
    pos[ve[i]] = i + n;
  }

  vector<vector<int>> adj(n + sz);

  for (int i = 0; i < n; i++) {
    for (int el : se[i]) {
      int k = pos[el];
      adj[i].push_back(pos);
      adj[pos].push_back(i);
    }
  }

  found = false;
  for (int i = 0; i < n; i++) {
    
    if (found) {
      break;
    }
  }

  return;

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