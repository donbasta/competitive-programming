#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  string s, t;
  cin >> n >> s >> t;
  string abc = "abc";
  vector<string> res;
  do {
    string cur;
    for (int i = 0; i < n; ++i) cur += abc;
    res.push_back(cur);
    res.push_back(string(n, abc[0]) + string(n, abc[1]) + string(n, abc[2]));
  } while (next_permutation(abc.begin(), abc.end()));
  
  for (auto str : res) {
    if (str.find(s) == string::npos && str.find(t) == string::npos) {
      cout << "YES" << '\n' << str << '\n';
      return;
    }
  }
  
  assert(0);
  cout << "NO" << '\n';
  
  return;
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