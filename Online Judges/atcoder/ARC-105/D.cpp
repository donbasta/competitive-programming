#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<int> ve(n);
  for(int i = 0; i < n; i++) {
    cin >> ve[i];
  }
  if(n & 1) {
    cout << "Second";
  } else {
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
      mp[ve[i]]++;
    }
    bool ok = 1;
    for(auto i : mp) {
      ok &= (i.second % 2 == 0);
    }
    if(ok) {
      cout << "Second";
    } else {
      cout << "First";
    }
  }
  cout << '\n';
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