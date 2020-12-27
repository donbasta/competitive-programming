#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> ans;
  int le = 0, ri = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      ans.push_back(le);
      le ^= 1;
    } else if (s[i] == ')') {
      ans.push_back(ri);
      ri ^= 1;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << (ans[i] ? '1' : '0');
  }
  cout << '\n';
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