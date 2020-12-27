#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;



void solve() {
  cin >> n;
  for(int i = 0; i < 3 * n; i++) {
    cin >> ar[i];
    ada[ar[i]] = 1;
  }
  for(int i = 0; i < 3 * n; i += 3) {
    tri[i] = {ar[i], ar[i + 1], ar[i + 2]};
  }
  vector<int> be;
  for(int i = 1; i <= 6 * n; i++) {
    if(!ada[i]) be.push_back(i);
  }
  for(int i = 0; i < )
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