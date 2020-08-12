#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<int> ve(1, 0);
  for(int i = 0; i < n; i++) {
    int t;
    cin >> t;
    ve.push_back(t);
  }
  ve.push_back(1800);
  ld temp = 0.0;
  for(int i = 1; i < (int)ve.size(); i++) {
    int dis = ve[i] - ve[i - 1];
    ld lol = (ld) dis * dis * (0.5);
    temp += lol;
  }
  temp = temp / (ld) (1800 - ve[n]);
  temp += (ld) ve[1];
  cout << fixed << setprecision(20) << temp << '\n';
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