#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAX = 100000;

int n;
bitset<MAX + 5> bt(1);

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    bt |= (bt << x);
  }
  vector<int> ve;
  for(int i = 1; i <= MAX; i++) {
    if(bt.test(i)) ve.emplace_back(i);
  }
  cout << (int)ve.size() << '\n';
  for(auto& i : ve) {cout << i << ' ';}
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