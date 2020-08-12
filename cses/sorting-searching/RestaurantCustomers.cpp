#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int M = 2e5;

int tn[2 * M + 5], cnt[2 * M + 5];


unordered_map<int, int> mp;

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> tim(n);
  vector<int> cp;
  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    cp.push_back(a);
    cp.push_back(b + 1);
    tim[i] = make_pair(a, b);
  }
  sort(cp.begin(), cp.end());
  cp.resize(unique(cp.begin(), cp.end()) - cp.begin());
  for(int i = 1; i <= (int)cp.size(); i++) {
    mp[cp[i - 1]] = i;
  }
  for(int i = 0; i < n; i++) {
    tn[mp[tim[i].first]]++;
    tn[mp[tim[i].second + 1]]--;
  }
  int mx = -1;
  for(int i = 1; i <= (int)cp.size() + 1; i++) {
    cnt[i] = cnt[i - 1] + tn[i];
    mx = max(cnt[i], mx);
  }
  cout << mx << '\n';
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