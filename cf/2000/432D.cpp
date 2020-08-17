#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e5;

string S;
vector<int> z;
int cnt[N + 5];
bool ok[N + 5];

void ZAlgo(string s) {
  int n = (int) s.length();
  z.resize(n);
  for(int i = 0, l = 0, r = 0; i < n; i++) {
    if(i <= r)
      z[i] = min(r - i + 1, z[i - l]);
    while(i + z[i] < n && s[z[i]] == s[i + z[i]])
      z[i]++;
    if(i + z[i] - 1 > r)
      l = i, r = i + z[i] - 1;
  }
}

void solve() {
  cin >> S;
  int len = (int) S.length();
  ZAlgo(S);
  vector<pair<int, int>> ans;
  cnt[len] = 1, ok[len] = 1;
  for(int i = 1; i < len; i++) {
    if(i + z[i] == len) ok[z[i]] = true;
    cnt[z[i]]++;
  }
  ans.emplace_back(len, 1);
  for(int i = len - 1; i >= 0; i--) {
    cnt[i] += cnt[i + 1];
    if(ok[i]) ans.emplace_back(i, cnt[i]);
  }
  int k = (int)ans.size();
  cout << k << '\n';
  for(int i = k - 1; i >= 0; i--) {
    cout << ans[i].first << ' ' << ans[i].second << '\n';
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