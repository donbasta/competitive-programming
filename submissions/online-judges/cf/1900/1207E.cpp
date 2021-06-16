#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int ask(const vector<int>& ve) {
  int ret;
  cout << "?";
  for(auto& e : ve) {
    cout << ' ' << e;
  }
  cout << endl;
  cin >> ret;
  return ret;
}

void ans(int x) {
  cout << "! " << x << endl;
  exit(0);
}

void solve() {
  vector<int> ve;
  for(int i = 1; i <= 100; i++) {
    ve.emplace_back(i);
  }
  int ret1 = ask(ve);
  ve.clear();
  for(int i = 1; i <= 100; i++) {
    ve.emplace_back(i << 7);
  }
  int ret2 = ask(ve);
  int mask = (1 << 7) - 1;
  int jwb = (ret1 & (mask << 7)) | (ret2 & mask);
  ans(jwb);
}

int main() {

  int TC = 1;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}