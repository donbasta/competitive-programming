#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<int> ar(n);
  vector<pair<int, int>> ans, ve;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ve.emplace_back(x, i);
  }
  sort(ve.begin(), ve.end());
  for(int i = 0; i < n; i++) {
    ar[ve[i].second] = i + 1;
  }
  for(int i = n - 1; i > 0; i--) {
    vector<pair<int, int>> temp;
    for(int j = 0; j < i; j++) {
      if(ar[j] > ar[i])
        temp.emplace_back(ar[j], j);
    }
    sort(temp.begin(), temp.end());
    int now = ar[i];
    for(auto j : temp) {
      if(j.first != now)
        ans.push_back(make_pair(j.second, i));
      swap(ar[j.second], ar[i]);
    }
  }
  cout << (int)ans.size() << '\n'; 
  for(auto pr : ans) {
    cout << pr.first + 1 << ' ' << pr.second + 1 << '\n';
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