#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int M = 2e5;

unordered_map<int, int> mp;
int dp[2 * M + 5];

bool cmp(pair<int, int> a, pair<int, int> b) {
  if(a.second == b.second) return a.first < b.first;
  return a.second < b.second;
}

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> ve;
  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    ve.emplace_back(a, b);
  }
  sort(ve.begin(), ve.end(), cmp);
  int ans = 1, mx = ve[0].second;
  for(int i = 1; i < n; i++) {
    if(ve[i].first < mx) continue;
    else {
      ans++;
      mx = ve[i].second;
    }
  }
  cout << ans << '\n';
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